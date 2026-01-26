OPT_DEFS += -DUSER_NAME_H=\"$(USER_NAME).h\"

ifeq ($(LIB_TRANSLATE_JP_ENABLE),yes)
    SRC += libs/translate_jp.c
    OPT_DEFS += -DLIB_TRANSLATE_JP_ENABLE
endif
ifeq ($(LIB_DEFAULT_LAYER_TOGGLE_ENABLE),yes)
    SRC += libs/default_layer_toggle.c
    OPT_DEFS += -DLIB_DEFAULT_LAYER_TOGGLE_ENABLE
endif
ifeq ($(LIB_RGBLIGHT_LAYER_COLOR_ENABLE),yes)
    SRC += libs/rgblight_layer_color.c
    OPT_DEFS += -DLIB_RGBLIGHT_LAYER_COLOR_ENABLE
endif
