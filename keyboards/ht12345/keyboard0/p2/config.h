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

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 18

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Encoder port configurator */

// This is a 7-bit address, that gets left-shifted and bit 0
// set to 0 for write, 1 for read (as per I2C protocol)
// The address will vary depending on your wiring:
// 0b1110100 AD <-> GND
// 0b1110101 AD <-> SCL
// 0b1110110 AD <-> SDA
// 0b1110111 AD <-> VCC
#define DRIVER_COUNT 3
#define DRIVER_ADDR_1 0b1110101
#define DRIVER_ADDR_2 0b1110110
#define DRIVER_ADDR_3 0b1110111
// #define ISSI_3731_DEGHOST

#define DRIVER_1_LED_TOTAL 32
#define DRIVER_2_LED_TOTAL 32
#define DRIVER_3_LED_TOTAL 26
#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL + DRIVER_3_LED_TOTAL)
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS // enable framebuffer effects
#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)

#define ENABLE_RGB_MATRIX_ALPHAS_MODS              // Static dual hue speed is hue for secondary hue
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN         // Static gradient top to bottom speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT      // Static gradient left to right speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_BREATHING                // Single hue brightness cycling animation
#define ENABLE_RGB_MATRIX_BAND_SAT                 // Single hue band fading saturation scrolling left to right
#define ENABLE_RGB_MATRIX_BAND_VAL                 // Single hue band fading brightness scrolling left to right
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT        // Single hue 3 blade spinning pinwheel fades saturation
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL        // Single hue 3 blade spinning pinwheel fades brightness
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT          // Single hue spinning spiral fades saturation
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL          // Single hue spinning spiral fades brightness
#define ENABLE_RGB_MATRIX_CYCLE_ALL                // Full keyboard solid hue cycling through full gradient
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT         // Full gradient scrolling left to right
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN            // Full gradient scrolling top to bottom
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN             // Full gradient scrolling out to in
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL        // Full dual gradients scrolling out to in
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON   // Full gradent Chevron shapped scrolling left to right
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL           // Full gradient spinning pinwheel around center of keyboard
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL             // Full gradient spinning spiral around center of keyboard
#define ENABLE_RGB_MATRIX_DUAL_BEACON              // Full gradient spinning around center of keyboard
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON           // Full tighter gradient spinning around center of keyboard
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS        // Full dual gradients spinning two halfs of keyboard
#define ENABLE_RGB_MATRIX_RAINDROPS                // Randomly changes a single key's hue
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS      // Randomly changes a single key's hue and saturation
#define ENABLE_RGB_MATRIX_HUE_BREATHING            // Hue shifts up a slight ammount at the same time then shifts back
#define ENABLE_RGB_MATRIX_HUE_PENDULUM             // Hue shifts up a slight ammount in a wave to the right then back to the left
#define ENABLE_RGB_MATRIX_HUE_WAVE                 // Hue shifts up a slight ammount and then back down in a wave to the right
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL            // Single hue fractal filled keys pulsing horizontally out to edges
#define ENABLE_RGB_MATRIX_PIXEL_RAIN               // Randomly light keys with random hues
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP	        // Enables RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN	            // Enables RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE     // Enables RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE            // Enables RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Enables RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Enables RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Enables RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Enables RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Enables RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Enables RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH                    // Enables RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH               // Enables RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH              // Enables RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH         // Enables RGB_MATRIX_SOLID_MULTISPLASH

#define WEAR_LEVELING_BACKING_SIZE 4096
#define WEAR_LEVELING_LOGICAL_SIZE 2048

#define WPM_SAMPLE_SECONDS 2
#define WPM_LAUNCH_CONTROL
