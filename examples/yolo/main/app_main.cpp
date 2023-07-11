#include <inttypes.h>
#include <stdio.h>

#include "edgelab.h"
#include "el_display_esp.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "meter.h"
#include "sdkconfig.h"
#include "yolo_model_data.h"

#define kTensorArenaSize (1024 * 1024)

uint16_t color[] = {
    0x0000,
    0x001F,
    0x03E0,
    0x7FE0,
    0xFFFF,
};

extern "C" void app_main(void)
{
    Display *display = new DisplayEsp();

    display->init();

    InferenceEngine *engine = new TFLiteEngine();
    uint8_t *tensor_arena =
        (uint8_t *)heap_caps_malloc(kTensorArenaSize, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    engine->init(tensor_arena, kTensorArenaSize);
    engine->load_model(g_yolo_model_data, g_yolo_model_data_len);
    Algorithm *algorithm = new Yolo(*engine);
    el_img_t img;
    img.data = (uint8_t *)gImage_meter;
    img.size = sizeof(gImage_meter);
    img.width = 240;
    img.height = 240;
    img.format = EL_PIXEL_FORMAT_RGB888;
    img.rotate = EL_PIXEL_ROTATE_0;

    algorithm->init();
    algorithm->run(&img);
    uint32_t preprocess_time = algorithm->get_preprocess_time();
    uint32_t run_time = algorithm->get_run_time();
    uint32_t postprocess_time = algorithm->get_postprocess_time();

    EL_INFO("preprocess_time: %d", preprocess_time);
    EL_INFO("run_time: %d", run_time);
    EL_INFO("postprocess_time: %d", postprocess_time);

    el_img_t img_out;
    img_out.data = (uint8_t *)heap_caps_malloc(240 * 240 * 2, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    img_out.size = 240 * 240 * 2;
    img_out.width = 240;
    img_out.height = 240;
    img_out.format = EL_PIXEL_FORMAT_RGB565;
    img_out.rotate = EL_PIXEL_ROTATE_0;

    el_img_convert(&img, &img_out);

    for (int i = 0; i < algorithm->get_result_size(); i++) {
        const el_box_t *box = static_cast<const el_box_t *>(algorithm->get_result(i));
        EL_INFO(
            "box: %d, %d, %d, %d, %d, %d", box->x, box->y, box->w, box->h, box->target, box->score);
        uint16_t x = box->x - box->w / 2;
        uint16_t y = box->y - box->h / 2;
        el_draw_rect(&img_out, x, y, box->w, box->h, color[i%5], 4);
    }
    EL_INFO("draw done");

    display->show(&img_out);

    // delete display;
    // delete engine;
    // delete algorithm;
    // heap_caps_free(tensor_arena);
    // heap_caps_free(img_out.data);
    EL_INFO("done");
    while (1) {
        EL_INFO(".");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
