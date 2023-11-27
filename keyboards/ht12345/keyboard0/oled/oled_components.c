

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

    // draw the indicator for the highest layer
    if (highest_layer < num_layers - 1) {
        draw_rect_filled_soft(x + highest_layer * 12, y, 11, 11, true);
    }

    // draw the text for the layers between 0 and num_layers-1
    for (int i = 0; i < num_layers; ++i) {
        write_char_at_pixel_xy(x + 3 + i * 12, y + 2, '0' + i, highest_layer == i);
    }

    // draw the indicator for the highest layer if it is greater than num_layers-1
    if (highest_layer >= num_layers - 1) {
        draw_rect_filled_soft(x + (num_layers - 1) * 12, y, 11, 11, true);
        write_char_at_pixel_xy(x + 3 + (num_layers - 1) * 12, y + 2, highest_layer + '0', highest_layer >= (num_layers - 1));
    }
}

// draws WPM info
#    ifdef WPM_ENABLE
char wpm_str[10];
void draw_wpm(int wpm_x, int wpm_y, bool full_label) {
    sprintf(wpm_str, full_label ? "W:%03d" : "WPM:%03d", get_current_wpm());
    write_chars_at_pixel_xy(wpm_x + (full_label ? 0 : 6), wpm_y, wpm_str, false);
}
#    endif

// draws matrix display if WPM counter is disabled
void draw_matrix_display(int matrix_x, int matrix_y) {
    // matrix
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        for (uint8_t y = 0; y < MATRIX_COLS; y++) {
            bool on = (matrix_get_row(x) & (1 << y)) > 0;
            oled_write_pixel(matrix_x + y + 2, matrix_y + x + 2, on);
        }
    }

    // outline
    draw_line_h(matrix_x + 1, matrix_y, MATRIX_COLS + 3, true);
    draw_line_h(matrix_x + 1, matrix_y + MATRIX_ROWS + 3, MATRIX_COLS + 3, true);
    draw_line_v(matrix_x, matrix_y + 1, MATRIX_ROWS + 2, true);
    draw_line_v(matrix_x + MATRIX_COLS + 4, matrix_y + 1, MATRIX_ROWS + 2, true);
}
