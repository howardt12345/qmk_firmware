#   define ANIM_FRAME_DURATION 150
#   define OLED_TIMEOUT 1000 * 15 // how long to wait before turning off oled


enum oled_modes {
    OLED_DEFAULT,
    OLED_BONGO,
    OLED_LUNA,
    _NUM_OLED_MODES
};

// OLED Behavior
uint32_t oled_sleep_timer;
uint32_t timeout_timer = 0;
uint32_t anim_timer = 0;

bool oled_redraw;

#include "oled_functions.c"
#include "oled_components.c"
#include "bongo_cat.c"
#include "dashboard.h"
#include "keyboard0.h"
#include "luna.c"
