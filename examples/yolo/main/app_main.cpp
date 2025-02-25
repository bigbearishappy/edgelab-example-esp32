/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "app_lcd.h"
#include "app_camera.h"
#include "algo_yolo.hpp"

static QueueHandle_t xQueueAIFrame = NULL;
static QueueHandle_t xQueueLCDFrame = NULL;

extern "C" void app_main()
{

  xQueueAIFrame = xQueueCreate(2, sizeof(camera_fb_t *));
  xQueueLCDFrame = xQueueCreate(2, sizeof(camera_fb_t *));

  register_camera(PIXFORMAT_RGB565, FRAMESIZE_240X240, 2, xQueueAIFrame);
  register_algo_yolo(xQueueAIFrame, NULL, NULL, xQueueLCDFrame, false);
  register_lcd(xQueueLCDFrame, NULL, true);

}
