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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x1234
#define PRODUCT_ID 0x5679
#define DEVICE_VER 0x0000
#define MANUFACTURER ht12345
#define PRODUCT numpad
#define DESCRIPTION numpad by ht12345

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS \
    { F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS \
    { E6, B4, B5, C6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Encoder port configurator */
#define ENCODERS_PAD_A \
    { D4, F5 }  // ROT1
#define ENCODERS_PAD_B \
    { D7, F6 }  // ROT2
#define ENCODER_DIRECTION_FLIP
#define ENCODER_RESOLUTION 4

/* OLED size */
#define OLED_DISPLAY_128X64

// The pin connected to the data pin of the LEDs
#define RGB_DI_PIN F4
// The number of LEDs connected
#define DRIVER_LED_TOTAL 18

#define ENABLE_RGB_MATRIX_CYCLE_ALL         // Full keyboard solid hue cycling through full gradient
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT  // Full gradient scrolling left to right
#define RGB_MATRIX_STARTUP_SPD 127          // Sets the default animation speed, if none has been set
