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

#ifdef OLED_ENABLE

#include "oled.h"

void update_kb_eeprom(void) {
    eeconfig_update_kb(user_config.raw);
}

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    oled_redraw = true;
    return OLED_ROTATION_180;  // flips the display 180 degrees
};
bool oled_task_kb(void) {
    if (oled_redraw) {
        oled_clear();
        oled_redraw = false;
    }

    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        oled_clear();
        switch(user_config.oled_mode) {
            case OLED_BONGO:
                draw_bongo_table();
                draw_bongocat();
                break;
            case OLED_LUNA:
                draw_luna_ui();
                render_luna(0, 0);
                break;
            default:
                draw_dashboard();
                break;
        }
    } else if (timer_elapsed32(timeout_timer) > OLED_TIMEOUT) {
        oled_off();
    }

    return false;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {\
    timeout_timer = timer_read32();
    oled_on();

    switch (keycode) {
        case OLED_PREV:
            if (record->event.pressed) {
                user_config.oled_mode = (user_config.oled_mode - 1) % _NUM_OLED_MODES;
                update_kb_eeprom();
            }
            oled_redraw = true;
            break;
        case OLED_NEXT:
            if (record->event.pressed) {
                user_config.oled_mode = (user_config.oled_mode + 1) % _NUM_OLED_MODES;
                update_kb_eeprom();
            }
            oled_redraw = true;
            break;
    }

    return process_record_user(keycode, record);
}

void keyboard_post_init_kb(void) {
    user_config.raw = eeconfig_read_kb();

    keyboard_post_init_user();
}

#endif
