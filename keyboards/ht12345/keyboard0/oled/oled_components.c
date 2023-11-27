

void draw_num_lock(int x, int y, led_t led_state) {
    draw_text_rectangle(x, y, 5 + (3 * 6), "NUM", led_state.num_lock);
}

void draw_caps_lock(int x, int y, led_t led_state) {
    draw_text_rectangle(x, y, 5 + (3 * 6), "CAP", led_state.caps_lock);
}

void draw_scroll_lock(int x, int y, led_t led_state) {
    draw_text_rectangle(x, y, 5 + (3 * 6), "SCR", led_state.scroll_lock);
}

void draw_keyboard_layers(int x, int y, int num_layers) {
    if (num_layers <= 0 || num_layers > DYNAMIC_KEYMAP_LAYER_COUNT) {
        num_layers = DYNAMIC_KEYMAP_LAYER_COUNT;
    }

    uint8_t highest_layer = get_highest_layer(layer_state);
    if (highest_layer < num_layers) {
        draw_rect_filled_soft(x + highest_layer * 12, y, 11, 11, true);
    } else {
        // indicator for layers above num_layers - 1
        draw_rect_filled_soft(x + (num_layers) * 12, y, 11, 11, true);
        write_char_at_pixel_xy(x + 3 + (num_layers) * 12, y + 2, highest_layer + 0x30, highest_layer > (num_layers));
    }

    // indicators for layers 0 to num_layers - 1
    for (int i = 0; i < num_layers; ++i) {
        write_char_at_pixel_xy(x + 3 + i * 12, y + 2, '0' + i, highest_layer == i);
    }
}
