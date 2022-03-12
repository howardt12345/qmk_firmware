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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off

	[0] = LAYOUT(
		KC_NLCK, KC_PSLS, KC_PAST, RGB_TOG,
		KC_P7, KC_P8, KC_P9, KC_PMNS,
		KC_P4, KC_P5, KC_P6, KC_PPLS,
		KC_P1, KC_P2, KC_P3, KC_MPLY,
		KC_P0, KC_PDOT, KC_PENT, LT(1, KC_LALT)
    ),

	[1] = LAYOUT(
        KC_TRNS, KC_TRNS, RGB_RMOD, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )

    // clang-format on
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder, ROT1 */
        if (clockwise) {
            rgb_matrix_increase_val();
        } else {
            rgb_matrix_decrease_val();
        }
    } else if (index == 1) { /* Second encoder, ROT2 */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    oled_write_char(get_highest_layer(layer_state) + 0x30, false);
    oled_write_P(PSTR("\n"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    oled_write_P(PSTR("\n"), false);
    static char temp[20] = {0};
    snprintf(temp, sizeof(temp) + 1, "M:%3dH:%3dS:%3dV:%3d", rgb_matrix_config.mode, rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v);
    oled_write(temp, false);

    return false;
}
#endif
