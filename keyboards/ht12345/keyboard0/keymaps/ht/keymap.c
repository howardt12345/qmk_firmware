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

#include QMK_KEYBOARD_H
#include "tap_dance.c"
#include "common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
	[0] = LAYOUT(
		TD(TD_RGB),	KC_ESC,		TD(TD_RGB),	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		KC_PSCR,	KC_SCRL,	TD(TD_MDA),
		G(KC_D),	KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,	KC_EQL,		KC_BSPC,	KC_INS,		KC_HOME,	KC_PGUP,
		C(KC_X),	KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_LBRC,	KC_RBRC,	KC_BSLS,	KC_DEL,		KC_END,		KC_PGDN,
		C(KC_C),	KC_CAPS,	KC_A,		KC_S,		KC_D,		KC_F,		KC_G,		KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,							KC_ENT,
		C(KC_V),	KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,										KC_RSFT,	KC_UP,      TD(TD_MDA),
		KC_BTN1,	KC_LCTL,	KC_LGUI,	KC_LALT,										KC_SPC,								KC_RALT,	KC_RGUI,				LT(1, KC_APP),KC_RCTL,  KC_LEFT,	KC_DOWN,	KC_RGHT
	),

	[1] = LAYOUT(
		KC_TRNS,	QK_BOOT,	EE_CLR,     KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	RGB_TOG,	KC_TRNS,	KC_MUTE,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	RGB_HUI,	RGB_SAI,	RGB_VAI,
		OLED_PREV,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	RGB_HUD,	RGB_SAD,	RGB_VAD,
		OLED_NEXT,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,							KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,										KC_TRNS,	KC_MS_U,    KC_MUTE,
		KC_BTN2,	KC_TRNS,	KC_TRNS,	KC_TRNS,										KC_TRNS,							KC_TRNS,	KC_TRNS,				KC_TRNS,	KC_TRNS,	KC_MS_L,	KC_MS_D,	KC_MS_R
	)
    // clang-format on
};

// clang-format on

bool encoder_update_user(uint8_t index, bool clockwise) {
    /* Getting modifiers */
    uint8_t temp_mod = get_mods();
    uint8_t temp_osm = get_oneshot_mods();
    bool    is_ctrl  = (temp_mod | temp_osm) & MOD_MASK_CTRL;
    bool    is_shift = (temp_mod | temp_osm) & MOD_MASK_SHIFT;
    bool    is_alt   = (temp_mod | temp_osm) & MOD_MASK_ALT;

    /* Alt tab */
    bool is_alt_tab_active = false;

    if (index == 0) {  /* First encoder, ROT1 */
        if (is_ctrl) { /* If control is held down */
            // undo/redo
            if (clockwise) {
                tap_code16(C(KC_Y));
            } else {
                tap_code16(C(KC_Z));
            }
        } else if (is_alt) { /* If alt is held down */
            // alt tab functionality
            if (clockwise) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                tap_code16(KC_TAB);
            } else {
                tap_code16(S(KC_TAB));
            }
        } else if (is_shift) { /* If shift is held down */
            // change RGB Matrix speed
            if (clockwise) {
                rgb_matrix_increase_speed();
            } else {
                rgb_matrix_decrease_speed();
            }
        } else {
            // change RGB matrix brightness
            if (clockwise) {
                next_layer();
            } else {
                previous_layer();
            }
        }
    } else if (index == 1) {  /* Second encoder, ROT2 */
        if (IS_LAYER_ON(1)) { /* If menu is held down */
            // change RGB matrix mode
            if (clockwise) {
                rgb_matrix_step();
            } else {
                rgb_matrix_step_reverse();
            }
        } else if (is_ctrl) {  /* If control is held down */
            // change RGB light strip mode
            if (clockwise) {
                rgblight_step();
            } else {
                rgblight_step_reverse();
            }
        } else if (is_alt) { /* If alt is held down */
            // change RGB light strip saturation
            if (clockwise) {
                rgblight_increase_sat();
            } else {
                rgblight_decrease_sat();
            }
        } else if (is_shift) { /* If shift is held down */
            // change RGB light strip brightness
            if (clockwise) {
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
        } else {
            if (clockwise) {
                // Change volume
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return true;
}
