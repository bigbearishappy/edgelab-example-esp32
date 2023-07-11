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

#ifndef _EL_DEBUG_H_
#define _EL_DEBUG_H_

#include "el_common.h"
#include "el_porting.h"

#ifdef __cplusplus
extern "C"
{
#endif

//--------------------------------------------------------------------+
// Debug
//--------------------------------------------------------------------+

// CFG_EL_DEBUG for debugging
// 0 : no debug
// 1 : print error
// 2 : print warning
// 3 : print info
// 4 : print verbose
#if CFG_EL_DEBUG

#if CFG_EL_DEBUG_COLOR
#define EL_DEBUG_COLOR_RED "\033[31m"
#define EL_DEBUG_COLOR_GREEN "\033[32m"
#define EL_DEBUG_COLOR_YELLOW "\033[33m"
#define EL_DEBUG_COLOR_BLUE "\033[34m"
#define EL_DEBUG_COLOR_MAGENTA "\033[35m"
#define EL_DEBUG_COLOR_CYAN "\033[36m"
#define EL_DEBUG_COLOR_RESET "\033[0m"
#else
#define EL_DEBUG_COLOR_RED
#define EL_DEBUG_COLOR_GREEN
#define EL_DEBUG_COLOR_YELLOW
#define EL_DEBUG_COLOR_BLUE
#define EL_DEBUG_COLOR_MAGENTA
#define EL_DEBUG_COLOR_CYAN
#define EL_DEBUG_COLOR_RESET
#endif

#if CFG_EL_DEBUG_MORE_INFO
#define EL_DEBUG_MORE_INFO() el_printf("(%llu) %s: ", el_get_time_ms(), __func__);
#else
#define EL_DEBUG_MORE_INFO()
#endif

#if CFG_EL_DEBUG >= 1
#define EL_ERROR(...)                            \
    do                                           \
    {                                            \
        el_printf(EL_DEBUG_COLOR_RED "E "); \
        EL_DEBUG_MORE_INFO();                    \
        el_printf(__VA_ARGS__);                  \
        el_printf(EL_DEBUG_COLOR_RESET "\r\n");  \
    } while (0)
#else
#define EL_ERROR(...)
#endif

#if CFG_EL_DEBUG >= 2
#define EL_WARNING(...)                               \
    do                                                \
    {                                                 \
        el_printf(EL_DEBUG_COLOR_YELLOW "W "); \
        EL_DEBUG_MORE_INFO();                         \
        el_printf(__VA_ARGS__);                       \
        el_printf(EL_DEBUG_COLOR_RESET "\r\n");       \
    } while (0)
#else
#define EL_WARNING(...)
#endif
#if CFG_EL_DEBUG >= 3
#define EL_INFO(...)            \
    do                          \
    {                           \
        el_printf("I ");   \
        EL_DEBUG_MORE_INFO();   \
        el_printf(__VA_ARGS__); \
        el_printf("\r\n");      \
    } while (0)
#else
#define EL_INFO(...)
#endif
#if CFG_EL_DEBUG >= 4
#define EL_VERBOSE(...)          \
    do                           \
    {                            \
        el_printf("V "); \
        EL_DEBUG_MORE_INFO();    \
        el_printf(__VA_ARGS__);  \
        el_printf("\r\n");       \
    } while (0)
#else
#define EL_VERBOSE(...)
#endif
#else
#define EL_ERROR(...)
#define EL_WARNING(...)
#define EL_INFO(...)
#define EL_VERBOSE(...)
#endif

#if CFG_EL_ASSERT
#define EL_ASSERT(expr)                                    \
    do                                                     \
    {                                                      \
        if (!(expr))                                       \
        {                                                  \
            el_printf(EL_DEBUG_COLOR_RED "[ASSERT]");      \
            EL_DEBUG_MORE_INFO();                          \
            el_printf("Failed assertion `%s'\r\n", #expr); \
            el_printf(EL_DEBUG_COLOR_RESET);               \
            while (1)                                      \
            {                                              \
            }                                              \
        }                                                  \
    } while (0)
#else
#define EL_ASSERT(expr)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _EL_DEBUG_H_ */
