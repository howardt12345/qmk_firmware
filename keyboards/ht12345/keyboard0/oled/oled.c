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

#include "oled.h"

#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    oled_redraw = true;
    return OLED_ROTATION_180;  // flips the display 180 degrees
};
bool oled_task_kb(void) {
    if (oled_redraw) {
        oled_clear();
        oled_redraw = false;
    }
    switch(oled_mode) {
        case OLED_BONGO:
            draw_bongo_table();
            draw_bongocat();
            break;
        case OLED_LUNA:
            render_luna(0, 0);
            break;
        default:
            draw_dashboard();
            break;
    }

    return false;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {\
    timeout_timer = timer_read32();
    oled_on();

    switch (keycode) {
        case OLED_PREV:
            oled_redraw = true;
            if (record->event.pressed) {
                oled_mode = (oled_mode - 1) % _NUM_OLED_MODES;
            }
            break;
        case OLED_NEXT:
            oled_redraw = true;
            if (record->event.pressed) {
                oled_mode = (oled_mode + 1) % _NUM_OLED_MODES;
            }
            break;
    }

    return process_record_user(keycode, record);
}

#endif
