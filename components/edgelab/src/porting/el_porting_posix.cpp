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

#include "el_porting.h"

#if CFG_EL_PORTING_POSIX == 1

#include <inttypes.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void el_sleep(uint32_t ms)
{
    usleep(ms * 1000);
}

uint64_t el_get_time_ms(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000 + (uint64_t)ts.tv_nsec / 1000000;
}

uint64_t el_get_time_us(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000 + (uint64_t)ts.tv_nsec / 1000;
}

EL_ATTR_WEAK int el_printf(const char *fmt, ...)
{
    va_list args;
    int n;
    va_start(args, fmt);
    n = vprintf(fmt, args);
    va_end(args);
    return n;
}

EL_ATTR_WEAK int el_putchar(char c)
{
    return putchar(c);
}

EL_ATTR_WEAK void *el_malloc(size_t size)
{
    return malloc(size);
}

EL_ATTR_WEAK void *el_calloc(size_t nmemb, size_t size)
{
    return calloc(nmemb, size);
}

EL_ATTR_WEAK void el_free(void *ptr)
{
    free(ptr);
}

EL_ATTR_WEAK void el_reset(void)
{
    exit(0);
}

#endif