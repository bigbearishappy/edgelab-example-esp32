/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2023 Seeed Technology Co.,Ltd
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

#ifndef _EL_CAMERA_H_
#define _EL_CMAERA_H_

#include "el_common.h"
#include "el_cv.h"
#include "el_types.h"

class Camera {
   private:
    el_img_t _src_img;  // source image
    el_img_t _jpeg_img; // jpeg image
    size_t _width, _height;
    bool _is_present;
    bool _is_streaming;
    static el_res_t _available_res[];

   public:
    Camera(/* args */){};
    virtual ~Camera(){};
    virtual EL_ERR init(size_t width, size_t height) = 0;
    virtual EL_ERR deinit() = 0;
    virtual EL_ERR start_stream() = 0;
    virtual bool is_streaming() = 0;
    virtual EL_ERR stop_stream() = 0;
    virtual EL_ERR get_frame(el_img_t* img, bool jpeg = false) = 0;
    virtual EL_ERR get_resolutions(el_res_t** res, size_t* res_count) = 0;

    operator bool() { return _is_present; }

    size_t width() { return _width; }
    size_t height() { return _height; }
};

#endif /* _EL_VIDEO_H_ */
