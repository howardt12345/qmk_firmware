#include "common.h"

void previous_layer(void) {
    int8_t layer = get_highest_layer(layer_state);
    if (layer > 0) {
        layer_move(layer - 1);
    } else {
        layer_move(DYNAMIC_KEYMAP_LAYER_COUNT - 1);
    }
}

void next_layer(void) {
    int8_t layer = get_highest_layer(layer_state);
    if (layer < DYNAMIC_KEYMAP_LAYER_COUNT - 1) {
        layer_move(layer + 1);
    } else {
        layer_move(0);
    }
}
