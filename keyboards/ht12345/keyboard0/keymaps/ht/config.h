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

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

/* Tap dance config */
#define TAPPING_TERM 250

/* Mouse keys config */
#define MK_3_SPEED

/* RGBLIGHT config */
#define RGB_DI_PIN A9
#define RGBLED_NUM 30
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_DEFAULT_VAL 64
#define RGBLIGHT_DEFAULT_SPD 32
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_MOOD

/* RGB Matrix config */
#define RGB_MATRIX_STARTUP_SPD 16
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_ALL // Sets the default mode, if none has been set


#endif
