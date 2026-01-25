#include QMK_KEYBOARD_H

bool is_default_layer_base(void) {
    return IS_LAYER_ON(0);
}

bool is_default_layer_alt(void) {
    return IS_LAYER_ON(1);
}

bool process_default_layer_toggle(uint16_t keycode, keyrecord_t* record) {
    if (keycode == DF_TOGG) {
        if (record->event.pressed) {
            uint8_t next = is_default_layer_base() ? 1 : 0;
            set_single_persistent_default_layer(next);
#ifdef RGBLIGHT_LAYER_COLOR
            // apply color based only on new default layer (not momentary layers)
            rgblight_apply_layer_color(1UL << next);
#endif
        }
        return false;
    }
    return true;
}
