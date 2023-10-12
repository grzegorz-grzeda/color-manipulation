/**
 * MIT License
 * Copyright (c) 2023 Grzegorz Grzęda
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
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include "cmocka.h"

#include "color-manipulation.h"

static void test_convert_hsv_to_rgb(void** state) {
    color_hsv_t hsv = {.hue = 10, .saturation = 100, .value = 100};
    color_rgb_t rgb = {0};
    rgb = convert_color_hsv_to_rgb(hsv);
    assert_int_equal(rgb.red, 0xFF);
    assert_int_equal(rgb.green, 0x2A);
    assert_int_equal(rgb.blue, 0x00);

    hsv.hue = 77;
    hsv.saturation = 200;
    rgb = convert_color_hsv_to_rgb(hsv);
    assert_int_equal(rgb.red, 0xB7);
    assert_int_equal(rgb.green, 0xFF);
    assert_int_equal(rgb.blue, 0x00);

    hsv.hue = 140;
    hsv.value = 190;
    rgb = convert_color_hsv_to_rgb(hsv);
    assert_int_equal(rgb.red, 0x00);
    assert_int_equal(rgb.green, 0xFF);
    assert_int_equal(rgb.blue, 0x55);

    hsv.hue = 205;
    rgb = convert_color_hsv_to_rgb(hsv);
    assert_int_equal(rgb.red, 0x00);
    assert_int_equal(rgb.green, 0x95);
    assert_int_equal(rgb.blue, 0xFF);

    hsv.hue = 259;
    rgb = convert_color_hsv_to_rgb(hsv);
    assert_int_equal(rgb.red, 0x50);
    assert_int_equal(rgb.green, 0x00);
    assert_int_equal(rgb.blue, 0xFF);

    hsv.hue = 312;
    rgb = convert_color_hsv_to_rgb(hsv);
    assert_int_equal(rgb.red, 0xFF);
    assert_int_equal(rgb.green, 0x00);
    assert_int_equal(rgb.blue, 0xCC);
}

int main(int argc, char** argv) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_convert_hsv_to_rgb),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
