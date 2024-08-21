/*
Copyright 2023 Howard Tseng

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

/* Placement information for display elements */
#    define NUMLOCK_DISPLAY_X 0
#    define NUMLOCK_DISPLAY_Y 0

#    define CAPSLOCK_DISPLAY_X 26
#    define CAPSLOCK_DISPLAY_Y 0

#    define SCROLLLOCK_DISPLAY_X 52
#    define SCROLLLOCK_DISPLAY_Y 0

#    define LAYER_DISPLAY_X 0
#    define LAYER_DISPLAY_Y 20

// WPM variables
#    ifdef WPM_ENABLE
#        define WPM_DISPLAY_X 80
#        define WPM_DISPLAY_Y 2
#    else
// Matrix display
#        define MATRIX_DISPLAY_X 87
#        define MATRIX_DISPLAY_Y 0
#    endif

// RGB info variables
#    if defined RGB_MATRIX_ENABLE || defined RGBLIGHT_ENABLE
char rgb_str[10];
#        define RGB_INFO_DISPLAY_X 62
#        define RGB_INFO_DISPLAY_Y 22
#    endif

// RGB light specific variables
#    ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB lighting settings
extern rgblight_config_t rgblight_config;

uint8_t bkl_mode;
uint8_t bkl_hsv_h;
uint8_t bkl_hsv_s;
uint8_t bkl_hsv_v;
#    endif

// RGB Matrix specific variables
#    ifdef RGB_MATRIX_ENABLE
uint8_t matrix_mode;
uint8_t matrix_hsv_h;
uint8_t matrix_hsv_s;
uint8_t matrix_hsv_v;
#    endif

// Encoder information
#    ifdef ENCODER_ENABLE
#        define ENABLE_SLIDERS true // Enable encoder sliders
// encoder slider placement information
#        define ENCODER_DISPLAY_X 110
#        define ENCODER_DISPLAY_Y 0
#        define ENCODER_SLIDER_WIDTH 6
#        define ENCODER_SLIDER_SPACING 3

// encoder slider reset delay
#        define ENCODER_RESET_DELAY 2500
uint32_t encoder_timer = 0;

// encoder update variables

#        define NUMBER_OF_ENCODERS 2
bool    encoder_updating;
uint8_t encoder_slider_pos[NUMBER_OF_ENCODERS];
#    endif

// gets the text of the last changed RGB setting
void get_rgb_matrix_change(void) {
#    ifdef RGBLIGHT_ENABLE
    if (bkl_mode != rgblight_config.mode) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "BL M:%3d", rgblight_config.mode);
    } else if (bkl_hsv_h != rgblight_config.hue) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "BL H:%3d", rgblight_config.hue);
    } else if (bkl_hsv_s != rgblight_config.sat) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "BL S:%3d", rgblight_config.sat);
    } else if (bkl_hsv_v != rgblight_config.val) {
        snprintf(rgb_str, sizeof(rgb_str) + 1, "BL V:%3d", rgblight_config.val);
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
    timeout_timer = timer_read32();
    oled_on();
    encoder_updating = true;
    for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
        if (i == index) {
            encoder_slider_pos[i] = clockwise ? -1 : 1;
        }
    }
    return encoder_update_user(index, clockwise);
}
#    endif

// draws the num, caps, and scroll lock indicators
void draw_keyboard_locks(void) {
    led_t led_state = host_keyboard_led_state();
    draw_num_lock(NUMLOCK_DISPLAY_X, NUMLOCK_DISPLAY_Y, led_state);
    draw_caps_lock(CAPSLOCK_DISPLAY_X, CAPSLOCK_DISPLAY_Y, led_state);
    draw_scroll_lock(SCROLLLOCK_DISPLAY_X, SCROLLLOCK_DISPLAY_Y, led_state);
}

// draws the last changed RGB setting
#    if defined RGBLIGHT_ENABLE || defined RGB_MATRIX_ENABLE
void draw_rgb_matrix_change(void) {
    get_rgb_matrix_change();
    if (rgblight_is_enabled() || rgb_matrix_config.enable) {
        write_chars_at_pixel_xy(RGB_INFO_DISPLAY_X + (ENABLE_SLIDERS ? 0 : 18), RGB_INFO_DISPLAY_Y, rgb_str, false);
    } else {
        write_chars_at_pixel_xy(RGB_INFO_DISPLAY_X + (ENABLE_SLIDERS ? 0 : 18), RGB_INFO_DISPLAY_Y, " RGB:OFF", false);
    }
}
#    endif

// draws encoder sliders to indicate if encoder is being used
#    if defined ENCODER_ENABLE && ENABLE_SLIDERS
// Encoder slider component
void draw_encoder_slider(uint8_t enc_index) {
    uint8_t enc_x          = ENCODER_DISPLAY_X + (enc_index * ENCODER_SLIDER_WIDTH) + ((enc_index + 1) * ENCODER_SLIDER_SPACING);
    uint8_t encoder_height = OLED_DISPLAY_HEIGHT - (2 * ENCODER_DISPLAY_Y);
    draw_rect_soft(enc_x, ENCODER_DISPLAY_Y, ENCODER_SLIDER_WIDTH, encoder_height, true);
    if (encoder_updating) {
        // draw slider with offset if encoder is being updated
        uint8_t enc_offset = encoder_height * (encoder_slider_pos[enc_index] + 2) / 4;
        draw_rect_filled_soft(enc_x, ENCODER_DISPLAY_Y + enc_offset, ENCODER_SLIDER_WIDTH, encoder_height - enc_offset, true);
    } else {
        // default encoder state
        draw_rect_filled_soft(enc_x, ENCODER_DISPLAY_Y + (encoder_height / 2), ENCODER_SLIDER_WIDTH, encoder_height / 2, true);
    }
}

// draws all encoder sliders
void draw_encoder_sliders(void) {
    for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
        draw_encoder_slider(i);
    }
}

// reset encoder slider positions
void reset_encoders(void) {
    encoder_updating = false;
    for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
        encoder_slider_pos[i] = 0;
    }
}
#    endif

void draw_dashboard(void) {
    // draw keyboard layers
    draw_keyboard_layers(LAYER_DISPLAY_X, LAYER_DISPLAY_Y, 4);
    // draw dividing line
    #if defined ENCODER_ENABLE && ENABLE_SLIDERS
        draw_line_h(0, 15, ENABLE_SLIDERS ? 110 : 128, true);
    #else
        draw_line_h(0, 15, 128, true);
    #endif
    // draw keyboard locks
    draw_keyboard_locks();

    #if defined RGBLIGHT_ENABLE || defined RGB_MATRIX_ENABLE
        draw_rgb_matrix_change();
    #endif

    #ifdef WPM_ENABLE
        draw_wpm(WPM_DISPLAY_X, WPM_DISPLAY_Y, ENABLE_SLIDERS);
    #else
        draw_matrix_display(MATRIX_DISPLAY_X, MATRIX_DISPLAY_Y);
    #endif

    #if defined ENCODER_ENABLE && ENABLE_SLIDERS
        draw_encoder_sliders();
        // reset encoder slider positions after delay
        if (timer_elapsed32(encoder_timer) > ENCODER_RESET_DELAY) {
            encoder_timer = timer_read32();
            reset_encoders();
        }
    #endif
}
