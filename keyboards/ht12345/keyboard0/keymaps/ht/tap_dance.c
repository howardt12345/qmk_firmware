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

void dance_rgb(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            rgb_matrix_toggle();
            rgblight_toggle();
            break;
        case 2:
            rgb_matrix_step();
            break;
        case 3:
            rgb_matrix_step_reverse();
            break;
        default:
            reset_tap_dance(state);
            break;
    }
}

void dance_media(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_MPLY);
            break;
        case 2:
            tap_code16(KC_MNXT);
            break;
        case 3:
            tap_code16(KC_MPRV);
            break;
        default:
            reset_tap_dance(state);
            break;
    }
}

// Tap Dance declarations
enum {
    TD_RGB,
    TD_MDA,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_RGB] = ACTION_TAP_DANCE_FN(dance_rgb),
    [TD_MDA] = ACTION_TAP_DANCE_FN(dance_media),
};
