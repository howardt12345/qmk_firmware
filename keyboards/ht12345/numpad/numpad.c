#include "numpad.h"

#ifdef RGB_MATRIX_ENABLE
// clang-format off
led_config_t g_led_config = {{
    // Key Matrix to LED Index
    { 0,  1,  2,  NO_LED },
    { 4,  5,  6,  3 },
    { 8,  9,  10, 7 },
    { 11, 12, 13, NO_LED },
    { 15, 16, 14, 17 },
}, {
    // LED Index to Physical Position
    {0, 13}, /*Num*/ 	{56, 13}, /*/*/ 	{112, 13}, /***/ 	{168, 13}, /*-*/
    {0, 26}, /*7*/ 	    {56, 26}, /*8*/ 	{112, 26}, /*9*/ 	{168, 26}, /*+*/
    {0, 38}, /*4*/      {56, 38}, /*5*/ 	{112, 38}, /*6*/
    {0, 51}, /*1*/ 	    {56, 51}, /*2*/ 	{112, 51}, /*3*/ 	{168, 51}, /*Enter*/
    {0, 64}, /*0*/ 	    {112, 64}, /*.*/ 	{224, 64}, /*ALT*/
}, {
    // LED Index to Flag
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4,
}};
// clang-format on
__attribute__((weak)) void rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().num_lock) {
        rgb_matrix_set_color(0, 0xFF, 0xFF, 0xFF);
    }
}
#endif
