/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2023 Hongtai Liu (Seeed Technology Inc.)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include <stdint.h>

#include "el_common.h"
#include "el_display.h"
#include "esp_log.h"
#include "screen_driver.h"

#define CONFIG_LCD_MODULE_ESP_S3_EYE 1

#if CONFIG_LCD_MODULE_ESP_S3_EYE
#define BOARD_LCD_MOSI  47
#define BOARD_LCD_MISO -1
#define BOARD_LCD_SCK 21
#define BOARD_LCD_CS 44
#define BOARD_LCD_DC 43
#define BOARD_LCD_RST -1
#define BOARD_LCD_BL 48
#define BOARD_LCD_PIXEL_CLOCK_HZ (40 * 1000 * 1000)
#define BOARD_LCD_BK_LIGHT_ON_LEVEL 0
#define BOARD_LCD_BK_LIGHT_OFF_LEVEL !BOARD_LCD_BK_LIGHT_ON_LEVEL
#define BOARD_LCD_H_RES 240
#define BOARD_LCD_V_RES 240
#define BOARD_LCD_CMD_BITS 8
#define BOARD_LCD_PARAM_BITS 8
#define BOARD_LCD_ROTATE 0
#define BOARD_LCD_CONTROLLER SCREEN_CONTROLLER_ST7789
#define LCD_HOST SPI2_HOST
#elif CONFIG_LCD_MODULE_XIAO_S3
#define BOARD_LCD_MOSI 9
#define BOARD_LCD_MISO 8
#define BOARD_LCD_SCK 7
#define BOARD_LCD_CS 2
#define BOARD_LCD_DC 4
#define BOARD_LCD_RST -1
#define BOARD_LCD_BL -1
#define BOARD_LCD_PIXEL_CLOCK_HZ (40 * 1000 * 1000)
#define BOARD_LCD_BK_LIGHT_ON_LEVEL 0
#define BOARD_LCD_BK_LIGHT_OFF_LEVEL !BOARD_LCD_BK_LIGHT_ON_LEVEL
#define BOARD_LCD_H_RES 240
#define BOARD_LCD_V_RES 240
#define BOARD_LCD_CMD_BITS 8
#define BOARD_LCD_PARAM_BITS 8
#define BOARD_LCD_ROTATE SCR_DIR_TBRL
#define BOARD_LCD_CONTROLLER SCREEN_CONTROLLER_GC9A01
#define LCD_HOST SPI2_HOST
#else
#error "No LCD module selected"
#endif

namespace edgelab {

class DisplayEsp : public Display {
   private:
    scr_driver_t _lcd;
    scr_info_t _lcd_info;

   public:
    DisplayEsp();
    ~DisplayEsp();
    EL_ERR init() override;
    EL_ERR deinit() override;
    EL_ERR show(const el_img_t *img) override;
};
} // namespace edgelab
