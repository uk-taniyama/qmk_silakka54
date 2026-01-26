#pragma once
#include QMK_KEYBOARD_H

#ifdef LIB_TRANSLATE_JP_ENABLE
#    include "_translate_jp.h"
#endif

#ifdef LIB_DEFAULT_LAYER_TOGGLE_ENABLE
#    include "_default_layer_toggle.h"
#endif

#ifdef LIB_RGBLIGHT_LAYER_COLOR_ENABLE
#    include "_rgblight_layer_color.h"
#endif
