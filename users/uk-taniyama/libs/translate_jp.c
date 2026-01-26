#include "libs.h"
#include "keymap_japanese.h"

// NOTE register_code/unregister_code works better than tap_code16.

#define MAX_TRANSLATED_KEYS 4

typedef struct {
    uint16_t original_keycode;
    uint16_t registered_code;
    bool     added_shift;
    bool     removed_shift;
} trans_state_t;

static trans_state_t trans_states[MAX_TRANSLATED_KEYS] = {0};

static trans_state_t* get_trans_state(uint16_t keycode) {
    for (int i = 0; i < MAX_TRANSLATED_KEYS; i++) {
        if (trans_states[i].original_keycode == keycode) {
            return &trans_states[i];
        }
    }
    return NULL;
}

void register_translated_code(uint16_t original, uint16_t code) {
    // Find an empty slot
    trans_state_t* state = get_trans_state(KC_NO);
    if (state == NULL) {
        return;
    }

    state->original_keycode = original;
    state->added_shift      = false;
    state->removed_shift    = false;
    state->registered_code  = code & QK_BASIC_MAX;

    if (code & QK_LSFT) {
        // Shift is required but not currently pressed -> Add Weak Shift
        if (!(get_mods() & MOD_MASK_SHIFT)) {
            add_weak_mods(MOD_BIT_LSHIFT);
            state->added_shift = true;
        }
    } else {
        // Shift is not required but currently pressed -> Remove Real Shift
        if (get_mods() & MOD_MASK_SHIFT) {
            del_mods(MOD_BIT_LSHIFT);
            state->removed_shift = true;
        }
    }
    register_code(state->registered_code);
}

void unregister_translated_code(uint16_t original) {
    // Find the corresponding key
    trans_state_t* state = get_trans_state(original);
    if (state == NULL) {
        return;
    }

    unregister_code(state->registered_code);

    if (state->added_shift) {
        del_weak_mods(MOD_BIT_LSHIFT);
    }
    if (state->removed_shift) {
        add_mods(MOD_BIT_LSHIFT);
    }

    state->original_keycode = KC_NO;
}

void send_translate_code(uint16_t original, uint16_t code, bool pressed) {
    if (pressed) {
        register_translated_code(original, code);
    } else {
        unregister_translated_code(original);
    }
}

void send_translate_jp_code(uint16_t original, uint16_t normal_code, uint16_t shifted_code, bool pressed) {
    // Determine based on current Mod state when pressed, search and release using original keycode when released
    if (pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
            register_translated_code(original, shifted_code);
        } else {
            register_translated_code(original, normal_code);
        }
    } else {
        unregister_translated_code(original);
    }
}

void send_translate_jp_grv(uint16_t original, uint16_t normal_code, uint16_t shifted_code, bool pressed) {
    if (pressed) {
        uint8_t mods = get_mods();
        if (mods & MOD_MASK_ALT) {
            register_translated_code(original, JP_ZKHK);
        } else if (mods & MOD_MASK_SHIFT) {
            register_translated_code(original, shifted_code);
        } else {
            register_translated_code(original, normal_code);
        }
    } else {
        unregister_translated_code(original);
    }
}

void send_alt_grv(uint16_t keycode, keyrecord_t* record) {
    uint8_t saved_mods = get_mods();
    set_mods(MOD_MASK_ALT);
    register_code(KC_GRV);
    unregister_code(KC_GRV);
    set_mods(saved_mods);
}

bool process_translate_jp(uint16_t keycode, keyrecord_t* record) {
#define TRANS_GRV(code, jpCode, jpSCode)                                     \
    case code:                                                               \
        send_translate_jp_grv(code, jpCode, jpSCode, record->event.pressed); \
        return false;
#define TRANS(code, jpCode, jpSCode)                                          \
    case code:                                                                \
        send_translate_jp_code(code, jpCode, jpSCode, record->event.pressed); \
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
