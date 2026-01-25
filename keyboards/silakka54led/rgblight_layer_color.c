#include QMK_KEYBOARD_H

const hsv_t rgblight_layer_colors[] = {
    {HSV_BLUE},    //
    {HSV_RED},     //
    {HSV_GREEN},   //
    {HSV_CYAN},    //
    {HSV_PURPLE},  //
    {HSV_ORANGE},  //
    {HSV_YELLOW},  //
    {HSV_MAGENTA}, //
};

static inline void rgblight_apply_layer_color(layer_state_t next_state) {
    uint8_t      layer = get_highest_layer(next_state);
    const hsv_t* hsv   = rgblight_layer_colors + layer;
    rgblight_sethsv_noeeprom(hsv->h, hsv->s, hsv->v);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_apply_layer_color(state | layer_state);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_apply_layer_color(state | default_layer_state);
    return state;
}
