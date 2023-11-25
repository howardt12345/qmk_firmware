
#include "oled_functions.c"
#include "bongo_cat.c"
// #include "dashboard.h"
#include "keyboard0.h"

enum oled_modes {
    OLED_DEFAULT,
    OLED_BONGO,
    OLED_OFF,
    _NUM_OLED_MODES
};

// OLED Behavior
extern uint8_t oled_mode;
extern uint32_t oled_sleep_timer;
