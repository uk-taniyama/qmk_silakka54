#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

#ifndef KEY_OVERRIDE_JP
#    define KEY_OVERRIDE_JP(trigger_mods, trigger, replacement) ko_make_basic(trigger_mods, trigger, replacement)
#endif

// ` ~
const key_override_t key_override_jp_grv   = KEY_OVERRIDE_JP(0, KC_GRV, JP_GRV);
const key_override_t key_override_jp_s_grv = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_GRV, JP_TILD);
const key_override_t key_override_jp_a_grv = KEY_OVERRIDE_JP(MOD_MASK_ALT, KC_GRV, JP_ZKHK);

// 2 @
const key_override_t key_override_jp_s_2 = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_2, JP_AT);

// 6 ^
const key_override_t key_override_jp_s_6 = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_6, JP_CIRC);

// 7 &
const key_override_t key_override_jp_s_7 = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_7, JP_AMPR);

// 8 *
const key_override_t key_override_jp_s_8 = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_8, JP_ASTR);

// 9 (
const key_override_t key_override_jp_s_9 = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_9, JP_LPRN);

//  0 )
const key_override_t key_override_jp_s_0 = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_0, JP_RPRN);

// - _
const key_override_t key_override_jp_s_mins = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_MINS, JP_UNDS);

// = +
const key_override_t key_override_jp_eql   = KEY_OVERRIDE_JP(0, KC_EQL, JP_EQL);
const key_override_t key_override_jp_s_eql = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_EQL, JP_PLUS);

//  [ {
const key_override_t key_override_jp_lbrc   = KEY_OVERRIDE_JP(0, KC_LBRC, JP_LBRC);
const key_override_t key_override_jp_s_lbrc = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_LBRC, JP_LCBR);

// ] }
const key_override_t key_override_jp_rbrc   = KEY_OVERRIDE_JP(0, KC_RBRC, JP_RBRC);
const key_override_t key_override_jp_s_rbrc = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_RBRC, JP_RCBR);

// \ |
const key_override_t key_override_jp_bsls   = KEY_OVERRIDE_JP(0, KC_BSLS, JP_YEN);
const key_override_t key_override_jp_s_bsls = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE);

// ; :
const key_override_t key_override_jp_s_coln = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_SCLN, JP_COLN);

// ' "
const key_override_t key_override_jp_quot   = KEY_OVERRIDE_JP(0, KC_QUOT, JP_QUOT);
const key_override_t key_override_jp_s_quot = KEY_OVERRIDE_JP(MOD_MASK_SHIFT, KC_QUOT, JP_DQUO);

// clang-format off
#define KEY_OVERRIDE_JP_LIST \
    &key_override_jp_a_grv, &key_override_jp_s_grv, &key_override_jp_grv, \
    &key_override_jp_s_2, \
    &key_override_jp_s_6, \
    &key_override_jp_s_7, \
    &key_override_jp_s_8, \
    &key_override_jp_s_9, \
    &key_override_jp_s_0, \
    &key_override_jp_s_mins, \
    &key_override_jp_s_eql, &key_override_jp_eql, \
    &key_override_jp_s_lbrc, &key_override_jp_lbrc, \
    &key_override_jp_s_rbrc, &key_override_jp_rbrc, \
    &key_override_jp_s_bsls, &key_override_jp_bsls, \
    &key_override_jp_s_coln, \
    &key_override_jp_s_quot, &key_override_jp_quot
// clang-format on

#ifndef KEY_OVERRIDES_OFF
const key_override_t *key_overrides[] = {KEY_OVERRIDE_JP_LIST};
#endif
