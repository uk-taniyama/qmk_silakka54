#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

static inline void send_translate_code(int code) {
    uint8_t saved_mods = get_mods();
    if (code & QK_LSFT) {
        add_mods(MOD_MASK_SHIFT);
    } else {
        del_mods(MOD_MASK_SHIFT);
    }
    register_code(code & QK_BASIC_MAX);
    unregister_code(code & QK_BASIC_MAX);
    set_mods(saved_mods);
}

static inline void send_translate_jp_code(int normal_code, int shifted_code) {
    uint8_t saved_mods = get_mods();
    bool    has_shift  = saved_mods & MOD_MASK_SHIFT;

    if (has_shift) {
        send_translate_code(shifted_code);
    } else {
        send_translate_code(normal_code);
    }
}

static inline void send_translate_jp_grv(int normal_code, int shifted_code) {
    uint8_t saved_mods = get_mods();
    bool    has_alt    = saved_mods & MOD_MASK_ALT;
    if (has_alt) {
        // alt + ` then send kc_grv
        send_translate_jp_code(JP_ZKHK, JP_ZKHK);
    } else {
        send_translate_jp_code(normal_code, shifted_code);
    }
}

static inline void send_alt_grv(uint16_t keycode, keyrecord_t* record) {
    uint8_t saved_mods = get_mods();
    add_mods(MOD_MASK_ALT);
    register_code(KC_GRV);
    unregister_code(KC_GRV);
    set_mods(saved_mods);
}

static inline bool process_translate_jp(uint16_t keycode, keyrecord_t* record) {
#define TRANS_GRV(code, jpCode, jpSCode)            \
    case code:                                      \
        if (!record->event.pressed) {               \
            send_translate_jp_grv(jpCode, jpSCode); \
        }                                           \
        return false;
#define TRANS(code, jpCode, jpSCode)                 \
    case code:                                       \
        if (!record->event.pressed) {                \
            send_translate_jp_code(jpCode, jpSCode); \
        }                                            \
        return false;
    switch (keycode) {
        TRANS_GRV(KC_GRV, JP_GRV, JP_TILD) // ` ~
        TRANS(KC_1, JP_1, JP_EXLM)         // 1 !
        TRANS(KC_2, JP_2, JP_AT)           // 2 @
        TRANS(KC_3, JP_3, JP_HASH)         // 3 #
        TRANS(KC_4, JP_4, JP_DLR)          // 4 $
        TRANS(KC_5, JP_5, JP_PERC)         // 5 %
        TRANS(KC_6, JP_6, JP_CIRC)         // 6 ^
        TRANS(KC_7, JP_7, JP_AMPR)         // 7 &
        TRANS(KC_8, JP_8, JP_ASTR)         // 8 *
        TRANS(KC_9, JP_9, JP_LPRN)         // 9 (
        TRANS(KC_0, JP_0, JP_RPRN)         // 0 )
        TRANS(KC_MINS, JP_MINS, JP_UNDS)   // - _
        TRANS(KC_EQL, JP_EQL, JP_PLUS)     // = +

        TRANS(KC_LBRC, JP_LBRC, JP_LCBR) // [ {
        TRANS(KC_RBRC, JP_RBRC, JP_RCBR) // ] }
        TRANS(KC_BSLS, JP_YEN, JP_PIPE)  // \ |

        TRANS(KC_SCLN, JP_SCLN, JP_COLN) // ; :
        TRANS(KC_QUOT, JP_QUOT, JP_DQUO) // ' "

        TRANS(KC_COMM, JP_COMM, JP_LABK) // , <
        TRANS(KC_DOT, JP_DOT, JP_RABK)   // . >
        TRANS(KC_SLSH, JP_SLSH, JP_QUES) // / ?
    }
    return true;
}
