// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include USER_NAME_H

#define IS_JP_LAYOUT() (is_default_layer_alt())
#include "libs/alt_ime.h"

TAP_HOLD(GRV_ESC, KC_GRV, KC_ESC);
TAP_HOLD_KEYS(&tap_hold_GRV_ESC);

enum layer_number {
    _US = 0,
    _JP,
    _US1,
    _JP1,
    _FN,
};

const layer_state_t jp_layer = (1U << _JP) | (1U << _JP1);

#define KEY_OVERRIDE_JP(mods, key, jp_key) ko_make_with_layers(mods, key, jp_key, jp_layer)

#include "libs/key_overrides_jp.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // default layer 0 : base
    [_US] = LAYOUT(
        GRV_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LALT, TT(_US1),KC_SPC,          KC_SPC,  TT(_US1),ALT_IME
    ),
    // default layer 1 : alt(jp)
    [_JP] = LAYOUT(
        GRV_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LALT, TT(_JP1),KC_SPC,          KC_SPC,  TT(_JP1),ALT_IME
    ),
    [_US1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                             KC_F11,  KC_F12,  XXXXXXX, KC_MINS, KC_EQL,  KC_BSPC,
        DF_TOGG, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, _______,
        _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                            KC_LGUI, TG(_US1),TG(_FN),         TG(_FN), TG(_US1),KC_LGUI
    ),
    [_JP1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                             KC_F11,  KC_F12,  XXXXXXX, KC_MINS, KC_EQL,  KC_BSPC,
        DF_TOGG, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, _______,
        _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                            KC_LGUI, TG(_JP1),TG(_FN),         TG(_FN), TG(_JP1),KC_LGUI
    ),
    [_FN] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, EE_CLR,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
                                            _______, TG(_FN), TG(_FN),          TG(_FN), TG(_FN), _______
    ),
    [5] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),
    [6] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),
    [7] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
                       'L', 'L', 'L',  'R', 'R', 'R'
    );
// clang-format on

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable = true;
    eeconfig_init();
#endif
#ifdef LIB_RGBLIGHT_LAYER_COLOR_ENABLE
    rgblight_apply_layer_color(layer_state | default_layer_state);
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_alt_ime(keycode, record) || !process_record_tap_hold(keycode, record)) {
        return false;
    }
    if (!process_default_layer_toggle(keycode, record)) {
        return false;
    }
    return true;
}
