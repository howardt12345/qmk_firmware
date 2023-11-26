

void draw_num_lock(int x, int y, led_t led_state) {
    draw_text_rectangle(x, y, 5 + (3 * 6), "NUM", led_state.num_lock);
}

void draw_caps_lock(int x, int y, led_t led_state) {
    draw_text_rectangle(x, y, 5 + (3 * 6), "CAP", led_state.caps_lock);
}

void draw_scroll_lock(int x, int y, led_t led_state) {
    draw_text_rectangle(x, y, 5 + (3 * 6), "SCR", led_state.scroll_lock);
}

void draw_keyboard_layers(int x, int y) {
    uint8_t highest_layer = get_highest_layer(layer_state);
    if (highest_layer < 4) {
        draw_rect_filled_soft(x + highest_layer * 12, y, 11, 11, true);
    } else {
        // indicator for layers above 3
        draw_rect_filled_soft(x + 48, y, 11, 11, true);
        write_char_at_pixel_xy(x + 3 + 48, y + 2, highest_layer + 0x30, highest_layer > 3);
    }

    // indicators for layers 0-3
    write_char_at_pixel_xy(x + 3, y + 2, '0', highest_layer == 0);
    write_char_at_pixel_xy(x + 3 + 12, y + 2, '1', highest_layer == 1);
    write_char_at_pixel_xy(x + 3 + 24, y + 2, '2', highest_layer == 2);
    write_char_at_pixel_xy(x + 3 + 36, y + 2, '3', highest_layer == 3);
}
