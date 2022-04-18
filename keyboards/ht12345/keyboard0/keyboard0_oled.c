/*
Copyright 2022 Howard Tseng

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keyboard0.h"
#include "oled_functions.c"

#ifdef OLED_ENABLE
#    define ANIM_FRAME_DURATION 1000 / 10 // how long each frame lasts in ms
uint32_t anim_timer = 0;

/* Placement information for display elements */
#    define NUMLOCK_DISPLAY_X 2
#    define NUMLOCK_DISPLAY_Y 19

#    define CAPSLOCK_DISPLAY_X 27
#    define CAPSLOCK_DISPLAY_Y 19

#    define SCROLLLOCK_DISPLAY_X 52
#    define SCROLLLOCK_DISPLAY_Y 19

#    define LAYER_DISPLAY_X 2
#    define LAYER_DISPLAY_Y 0

// WPM and RGB settings strings
#    ifdef WPM_ENABLE
char wpm_str[10];
#    endif
#    if defined RGB_MATRIX_ENABLE || defined RGBLIGHT_ENABLE
char rgb_str[10];
#    endif

#    ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB lighting settings
extern rgblight_config_t rgblight_config;

uint8_t bkl_mode;
uint8_t bkl_hsv_h;
uint8_t bkl_hsv_s;
uint8_t bkl_hsv_v;
#    endif

#    ifdef RGB_MATRIX_ENABLE
uint8_t matrix_mode;
uint8_t matrix_hsv_h;
uint8_t matrix_hsv_s;
uint8_t matrix_hsv_v;
#    endif

#    ifdef ENCODER_ENABLE
uint8_t encoder_index;
bool    encoder_clockwise;
#    endif

void get_rgb_matrix_change(void) {
#    ifdef RGBLIGHT_ENABLE
    if (bkl_mode != rgblight_config.mode) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "BK M:%3d", rgblight_config.mode);
    } else if (bkl_hsv_h != rgblight_config.hue) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "BK H:%3d", rgblight_config.hue);
    } else if (bkl_hsv_s != rgblight_config.sat) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "BK S:%3d", rgblight_config.sat);
    } else if (bkl_hsv_v != rgblight_config.val) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "BK V:%3d", rgblight_config.val);
    }

    bkl_mode  = rgblight_config.mode;
    bkl_hsv_h = rgblight_config.hue;
    bkl_hsv_s = rgblight_config.sat;
    bkl_hsv_v = rgblight_config.val;
#    endif

#    ifdef RGB_MATRIX_ENABLE
    if (matrix_mode != rgb_matrix_config.mode) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "MX M:%3d", rgb_matrix_config.mode);
    } else if (matrix_hsv_h != rgb_matrix_config.hsv.h) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "MX H:%3d", rgb_matrix_config.hsv.h);
    } else if (matrix_hsv_s != rgb_matrix_config.hsv.s) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "MX S:%3d", rgb_matrix_config.hsv.s);
    } else if (matrix_hsv_v != rgb_matrix_config.hsv.v) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "MX V:%3d", rgb_matrix_config.hsv.v);
    }

    matrix_mode  = rgb_matrix_config.mode;
    matrix_hsv_h = rgb_matrix_config.hsv.h;
    matrix_hsv_s = rgb_matrix_config.hsv.s;
    matrix_hsv_v = rgb_matrix_config.hsv.v;
#    endif
}

#    ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    encoder_index     = index;
    encoder_clockwise = clockwise;
    return encoder_update_user(index, clockwise);
}
#    endif

// draws indicators for the current keyboard layer
void draw_keyboard_layers(void) {
    uint8_t highest_layer;
    highest_layer = get_highest_layer(layer_state);
    if (highest_layer < 4) {
        draw_rect_filled_soft(LAYER_DISPLAY_X + highest_layer * 12, LAYER_DISPLAY_Y, 11, 11, true);
    } else {
        // indicator for layers above 3
        draw_rect_filled_soft(LAYER_DISPLAY_X + 48, LAYER_DISPLAY_Y, 11, 11, true);
        write_char_at_pixel_xy(LAYER_DISPLAY_X + 3 + 48, LAYER_DISPLAY_Y + 2, highest_layer + 0x30, highest_layer > 3);
    }

    // indicators for layers 0-3
    write_char_at_pixel_xy(LAYER_DISPLAY_X + 3, LAYER_DISPLAY_Y + 2, '0', highest_layer == 0);
    write_char_at_pixel_xy(LAYER_DISPLAY_X + 3 + 12, LAYER_DISPLAY_Y + 2, '1', highest_layer == 1);
    write_char_at_pixel_xy(LAYER_DISPLAY_X + 3 + 24, LAYER_DISPLAY_Y + 2, '2', highest_layer == 2);
    write_char_at_pixel_xy(LAYER_DISPLAY_X + 3 + 36, LAYER_DISPLAY_Y + 2, '3', highest_layer == 3);

    // draw dividing line
    draw_line_h(0, 14, 110, true);
}

// draws the num, caps, and scroll lock indicators
void draw_keyboard_locks(void) {
    led_t led_state = host_keyboard_led_state();
    draw_text_rectangle(NUMLOCK_DISPLAY_X, NUMLOCK_DISPLAY_Y, 5 + (3 * 6), "NUM", led_state.num_lock);
    draw_text_rectangle(CAPSLOCK_DISPLAY_X, CAPSLOCK_DISPLAY_Y, 5 + (3 * 6), "CAP", led_state.caps_lock);
    draw_text_rectangle(SCROLLLOCK_DISPLAY_X, SCROLLLOCK_DISPLAY_Y, 5 + (3 * 6), "SCR", led_state.scroll_lock);
}

bool oled_task_kb(void) {
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        oled_clear();
        draw_keyboard_locks();
        draw_keyboard_layers();
    }

    return false;
}

#endif
