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

#include "p2.h"
#ifdef RGB_MATRIX_ENABLE
const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
    /* Refer to IS31 manual for these locations
     *   driver
     *   |  R location
     *   |  |      G location
     *   |  |      |      B location
     *   |  |      |      | */
    {0, C1_1, C3_2, C4_2}, // LED1
    {0, C1_2, C2_2, C4_3}, // LED2
    {0, C1_3, C2_3, C3_3}, // LED3
    {0, C1_4, C2_4, C3_4}, // LED4
    {0, C1_5, C2_5, C3_5}, // LED5
    {0, C1_6, C2_6, C3_6}, // LED6
    {0, C1_7, C2_7, C3_7}, // LED7
    {0, C1_8, C2_8, C3_8}, // LED8
    {0, C9_1, C8_1, C7_1}, // LED9
    {0, C9_2, C8_2, C7_2}, // LED10
    {0, C9_3, C8_3, C7_3}, // LED11
    {0, C9_4, C8_4, C7_4}, // LED12
    {0, C9_5, C8_5, C7_5}, // LED13
    {0, C9_6, C8_6, C7_6}, // LED14
    {0, C9_7, C8_7, C6_6}, // LED15
    {0, C9_8, C7_7, C6_7}, // LED16

    {0, C1_9, C3_10, C4_10},  // LED17
    {0, C1_10, C2_10, C4_11}, // LED18
    {0, C1_11, C2_11, C3_11}, // LED19
    {0, C1_12, C2_12, C3_12}, // LED20
    {0, C1_13, C2_13, C3_13}, // LED21
    {0, C1_14, C2_14, C3_14}, // LED22
    {0, C1_15, C2_15, C3_15}, // LED23
    {0, C1_16, C2_16, C3_16}, // LED24
    {0, C9_9, C8_9, C7_9},    // LED25
    {0, C9_10, C8_10, C7_10}, // LED26
    {0, C9_11, C8_11, C7_11}, // LED27
    {0, C9_12, C8_12, C7_12}, // LED28
    {0, C9_13, C8_13, C7_13}, // LED29
    {0, C9_14, C8_14, C7_14}, // LED30
    {0, C9_15, C8_15, C6_14}, // LED31
    {0, C9_16, C7_15, C6_15}, // LED32

    {1, C1_1, C3_2, C4_2}, // LED33
    {1, C1_2, C2_2, C4_3}, // LED34
    {1, C1_3, C2_3, C3_3}, // LED35
    {1, C1_4, C2_4, C3_4}, // LED36
    {1, C1_5, C2_5, C3_5}, // LED37
    {1, C1_6, C2_6, C3_6}, // LED38
    {1, C1_7, C2_7, C3_7}, // LED39
    {1, C1_8, C2_8, C3_8}, // LED40
    {1, C9_1, C8_1, C7_1}, // LED41
    {1, C9_2, C8_2, C7_2}, // LED42
    {1, C9_3, C8_3, C7_3}, // LED43
    {1, C9_4, C8_4, C7_4}, // LED44
    {1, C9_5, C8_5, C7_5}, // LED45
    {1, C9_6, C8_6, C7_6}, // LED46
    {1, C9_7, C8_7, C6_6}, // LED47
    {1, C9_8, C7_7, C6_7}, // LED48

    {1, C1_9, C3_10, C4_10},  // LED49
    {1, C1_10, C2_10, C4_11}, // LED50
    {1, C1_11, C2_11, C3_11}, // LED51
    {1, C1_12, C2_12, C3_12}, // LED52
    {1, C1_13, C2_13, C3_13}, // LED53
    {1, C1_14, C2_14, C3_14}, // LED54
    {1, C1_15, C2_15, C3_15}, // LED55
    {1, C1_16, C2_16, C3_16}, // LED56
    {1, C9_9, C8_9, C7_9},    // LED57
    {1, C9_10, C8_10, C7_10}, // LED58
    {1, C9_11, C8_11, C7_11}, // LED59
    {1, C9_12, C8_12, C7_12}, // LED60
    {1, C9_13, C8_13, C7_13}, // LED61
    {1, C9_14, C8_14, C7_14}, // LED62
    {1, C9_15, C8_15, C6_14}, // LED63
    {1, C9_16, C7_15, C6_15}, // LED64

    {2, C1_1, C3_2, C4_2}, // LED65
    {2, C1_2, C2_2, C4_3}, // LED66
    {2, C1_3, C2_3, C3_3}, // LED67
    {2, C1_4, C2_4, C3_4}, // LED68
    {2, C1_5, C2_5, C3_5}, // LED69
    {2, C1_6, C2_6, C3_6}, // LED70
    {2, C1_7, C2_7, C3_7}, // LED71
    {2, C1_8, C2_8, C3_8}, // LED72
    {2, C9_1, C8_1, C7_1}, // LED73
    {2, C9_2, C8_2, C7_2}, // LED74
    {2, C9_3, C8_3, C7_3}, // LED75
    {2, C9_4, C8_4, C7_4}, // LED76
    {2, C9_5, C8_5, C7_5}, // LED77
    {2, C9_6, C8_6, C7_6}, // LED78
    {2, C9_7, C8_7, C6_6}, // LED79
    {2, C9_8, C7_7, C6_7}, // LED80

    {2, C1_9, C3_10, C4_10},  // LED81
    {2, C1_10, C2_10, C4_11}, // LED82
    {2, C1_11, C2_11, C3_11}, // LED83
    {2, C1_12, C2_12, C3_12}, // LED84
    {2, C1_13, C2_13, C3_13}, // LED85
    {2, C1_14, C2_14, C3_14}, // LED86
    {2, C1_15, C2_15, C3_15}, // LED87
    {2, C1_16, C2_16, C3_16}, // LED88
    {2, C9_15, C8_15, C6_14}, // LED89
    {2, C9_16, C7_15, C6_15}, // LED90
};
// clang-format off
led_config_t g_led_config = {{
      // Key Matrix to LED Index
    { NO_LED,   2,  NO_LED, 3,      4,      5,      6,  7,      8,      9,      10, 11, 12,     13,     14, 15,     NO_LED, NO_LED },
	{ 0,        1,  31,     30,     29,     28,     27, 26,     25,     24,     23, 22, 21,     20,     19, 18,     17,     16 },
	{ 48,       49, 32,     33,     34,     35,     36, 37,     38,     39,     40, 41, 42,     43,     44, 45,     46,     47 },
	{ 50,       51, 52,     53,     54,     55,     56, 57,     58,     59,     60, 61, 62,     NO_LED, 63, NO_LED, NO_LED, NO_LED },
	{ 67,       68, 69,     70,     71,     72,     73, 74,     75,     76,     77, 78, NO_LED, NO_LED, 79, NO_LED, 81,     NO_LED },
	{ 64,       65, 66,     89,     NO_LED, NO_LED, 88, NO_LED, NO_LED, NO_LED, 84, 85, NO_LED, 86,     87, 83,     82,     80 }
}, {
  // LED Index to Physical Position
    {0, 17}, /*M1*/ 	    {15, 17}, /*~*/ 	    {15, 0}, /*Esc*/ 	{39, 0}, /*F1*/ 	{51, 0}, /*F2*/ 	{63, 0}, /*F3*/ 	{75, 0}, /*F4*/ 	{93, 0}, /*F5*/ 	    {105, 0}, /*F6*/
    {116, 0}, /*F7*/ 	    {128, 0}, /*F8*/ 	    {146, 0}, /*F9*/ 	{158, 0}, /*F10*/ 	{170, 0}, /*F11*/ 	{182, 0}, /*F12*/ 	{200, 0}, /*PrtSc*/ {224, 17}, /*PgUp*/     {212, 17}, /*Home*/
    {200, 17}, /*Insert*/ 	{170, 17}, /*Backspace*/{158, 17}, /*+*/ 	{146, 17}, /*_*/ 	{134, 17}, /*)*/ 	{122, 17}, /*(*/ 	{111, 17}, /***/ 	{99, 17}, /*&*/ 	    {87, 17}, /*^*/
    {75, 17}, /*%*/ 	    {63, 17}, /*$*/ 	    {51, 17}, /*#*/ 	{39, 17}, /*@*/ 	{27, 17}, /*!*/ 	{33, 29}, /*Q*/ 	{45, 29}, /*W*/ 	{57, 29}, /*E*/ 	    {69, 29}, /*R*/
    {81, 29}, /*T*/ 	    {93, 29}, /*Y*/ 	    {105, 29}, /*U*/ 	{116, 29}, /*I*/ 	{128, 29}, /*O*/ 	{140, 29}, /*P*/ 	{152, 29}, /*{*/ 	{164, 29}, /*}*/ 	    {176, 29}, /*|*/
    {200, 29}, /*Delete*/ 	{212, 29}, /*End*/ 	    {224, 29}, /*PgDn*/ {0, 29}, /*M2*/ 	{15, 29}, /*Tab*/ 	{0, 41}, /*M3*/ 	{15, 41}, /*Caps*/ 	{36, 41}, /*A*/ 	    {48, 41}, /*S*/
    {60, 41}, /*D*/ 	    {72, 41}, /*F*/ 	    {84, 41}, /*G*/ 	{96, 41}, /*H*/ 	{108, 41}, /*J*/ 	{119, 41}, /*K*/ 	{131, 41}, /*L*/ 	{143, 41}, /*:*/ 	    {155, 41}, /*"*/
    {167, 41}, /*Enter*/ 	{0, 64}, /*M5*/ 	    {15, 64}, /*LCtrl*/ {30, 64}, /*LWin*/ 	{0, 52}, /*M4*/ 	{15, 52}, /*LShift*/{42, 52}, /*Z*/ 	{54, 52}, /*X*/ 	    {66, 52}, /*C*/
    {78, 52}, /*V*/ 	    {90, 52}, /*B*/ 	    {102, 52}, /*N*/ 	{113, 52}, /*M*/ 	{125, 52}, /*<*/ 	{137, 52}, /*>*/ 	{149, 52}, /*?*/ 	{161, 52}, /*RShift*/ 	{224, 64}, /*Right*/
    {212, 52}, /*Up*/ 	    {212, 64}, /*Down*/ 	{200, 64}, /*Left*/ {134, 64}, /*RAlt*/ {149, 64}, /*RWin*/ {164, 64}, /*Menu*/ {179, 64}, /*RCtrl*/{60, 64}, /*Space*/ 	{45, 64}, /*LAlt*/
}, {
  // LED Index to Flag
    1, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 1, 4, 1, 1, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 1, 4, 4, 1, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4,
}};
// clang-format on
bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(51, 0xFF, 0xFF, 0xFF);
    }
    return true;
}
#endif
