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


#ifdef OLED_ENABLE
char wpm_str[10];

bool oled_task_kb(void) {
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

    oled_write_P(PSTR("\n"), false);
    sprintf(wpm_str, "WPM: %03d", get_current_wpm());
    oled_write(wpm_str, false);
    return false;
}
#endif
