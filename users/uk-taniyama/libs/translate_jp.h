#pragma once
#include QMK_KEYBOARD_H

void send_alt_grv(uint16_t keycode, keyrecord_t *record);
bool process_translate_jp(uint16_t keycode, keyrecord_t *record);
