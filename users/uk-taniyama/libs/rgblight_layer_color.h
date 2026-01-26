#pragma once
#include QMK_KEYBOARD_H

void          rgblight_apply_layer_color(layer_state_t next_state);
layer_state_t default_layer_state_set_user(layer_state_t state);
layer_state_t layer_state_set_user(layer_state_t state);
