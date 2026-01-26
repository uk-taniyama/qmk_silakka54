#pragma once
#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

#ifndef US_ZKHK
#    define US_ZKHK A(KC_GRV)
#endif

#ifndef ALT_IME
#    define ALT_IME ALT_T(JP_ZKHK)
#endif

#ifndef IS_JP_LAYOUT
#    define IS_JP_LAYOUT() (false)
#endif

static inline bool process_record_alt_ime(uint16_t keycode, keyrecord_t *record) {
    if (keycode == ALT_IME && record->tap.count && record->event.pressed) {
        if (!IS_JP_LAYOUT()) {
            tap_code16(US_ZKHK);
            return false;
        }
        // JP layout: use the default Mod-Tap behavior (JP_ZKHK)
    }
#ifndef US_ZKHK_OFF
    if (keycode == US_ZKHK && record->event.pressed) {
        if (IS_JP_LAYOUT()) {
            tap_code16(JP_ZKHK);
            return false;
        }
        // US layout: use the default Mod-Tap behavior (ALT_IME)
    }
#endif
    return true;
}
