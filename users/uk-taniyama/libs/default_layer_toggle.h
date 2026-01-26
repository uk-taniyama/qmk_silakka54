#pragma once
#include QMK_KEYBOARD_H

bool is_default_layer_base(void);
bool is_default_layer_alt(void);
bool process_default_layer_toggle(uint16_t keycode, keyrecord_t* record);
