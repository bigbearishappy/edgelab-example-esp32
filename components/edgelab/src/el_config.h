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

#ifndef _EL_CONFIG_H_
#define _EL_CONFIG_H_

#define CFG_EL_PORTING_ESPRESSIF 1

#define CFG_EL_DEBUG 4
#define CFG_EL_DEBUG_COLOR 1
#define CFG_EL_DEBUG_MORE_INFO 1
#define CFG_EL_ASSERT 1

#define CFG_EL_FILESYSTEM 0

#define CFG_EL_TFLITE 1
#define CFG_EL_TFLITE_OP_RESOLVER_SIZE 128
#define CFG_EL_TFLITE_OP_CONV_2D 1
#define CFG_EL_TFLITE_OP_RESHAPE 1
#define CFG_EL_TFLITE_OP_SHAPE 1
#define CFG_EL_TFLITE_OP_PACK 1
#define CFG_EL_TFLITE_OP_PAD 1
#define CFG_EL_TFLITE_OP_PADV2 1
#define CFG_EL_TFLITE_OP_SUB 1
#define CFG_EL_TFLITE_OP_ADD 1
#define CFG_EL_TFLITE_OP_RELU 1
#define CFG_EL_TFLITE_OP_MAX_POOL_2D 1
#define CFG_EL_TFLITE_OP_SPLIT 1
#define CFG_EL_TFLITE_OP_CONCATENATION 1
#define CFG_EL_TFLITE_OP_RESIZE_NEAREST_NEIGHBOR 1
#define CFG_EL_TFLITE_OP_QUANTIZE 1
#define CFG_EL_TFLITE_OP_TRANSPOSE 1
#define CFG_EL_TFLITE_OP_LOGISTIC 1
#define CFG_EL_TFLITE_OP_MUL 1
#define CFG_EL_TFLITE_OP_SPLIT_V 1
#define CFG_EL_TFLITE_OP_STRIDED_SLICE 1
#define CFG_EL_TFLITE_OP_MEAN 1
#define CFG_EL_TFLITE_OP_SOFTMAX 1
#define CFG_EL_TFLITE_OP_DEPTWISE_CONV_2D 1
#define CFG_EL_TFLITE_OP_LEAKY_RELU 1

#define CFG_EL_LIB_JPEGENC 1

#endif /* _EL_CONFIG_H_ */