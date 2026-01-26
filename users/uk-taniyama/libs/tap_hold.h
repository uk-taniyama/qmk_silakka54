#pragma once
#include QMK_KEYBOARD_H

typedef struct {
    uint16_t tap_key;
    uint16_t hold_key;
} tap_hold_key_t;

#define TAP_HOLD_KEY(tap_key) LT(0, tap_key)

#define TAP_HOLD(NAME, tap_key, hold_key)                         \
    const uint16_t       NAME            = TAP_HOLD_KEY(tap_key); \
    const tap_hold_key_t tap_hold_##NAME = {tap_key, hold_key};

#define TAP_HOLD_KEYS(...)                                     \
    const tap_hold_key_t *tap_hold_keys[]     = {__VA_ARGS__}; \
    const size_t          tap_hold_keys_count = ARRAY_SIZE(tap_hold_keys);

bool process_record_tap_hold(uint16_t keycode, keyrecord_t *record);
