#include "libs.h"

#define LAYER_BASE 0
#define LAYER_ALT 1

bool is_default_layer_base(void) {
    return IS_LAYER_ON(LAYER_BASE);
}

bool is_default_layer_alt(void) {
    return IS_LAYER_ON(LAYER_ALT);
}

bool process_default_layer_toggle(uint16_t keycode, keyrecord_t* record) {
    if (keycode == DF_TOGG) {
        if (record->event.pressed) {
            uint8_t next = is_default_layer_base() != LAYER_BASE ? LAYER_BASE : LAYER_ALT;
            set_single_persistent_default_layer(next);
#ifdef LIB_RGBLIGHT_LAYER_COLOR_ENABLE
            // apply color based only on new default layer (not momentary layers)
            rgblight_apply_layer_color(1UL << next);
#endif
        }
        return false;
    }
    return true;
}
