#include "tap_hold.h"
#ifdef KEY_OVERRIDE_ENABLE
#    include "process_key_override.h"
#endif

extern const tap_hold_key_t *tap_hold_keys[];
extern const size_t          tap_hold_keys_count;

bool dispatch_key_code(uint16_t keycode, keyrecord_t *record) {
#ifdef KEY_OVERRIDE_ENABLE
    if (!process_key_override(keycode, record)) {
        return false;
    }
#endif
    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }
    return false;
}

bool process_record_tap_hold(uint16_t keycode, keyrecord_t *record) {
    for (size_t i = 0; i < tap_hold_keys_count; i++) {
        const tap_hold_key_t *hook = tap_hold_keys[i];

        // Check if the pressed key matches a tap-hold key
        if (keycode != TAP_HOLD_KEY(hook->tap_key)) {
            continue;
        }

        // If tapped, do the default behavior
        if (record->tap.count != 0) {
            dprintf("process_record_tap_hold:tap:%X, %X\n", keycode, hook->tap_key);
            return dispatch_key_code(hook->tap_key, record);
        }

        // If held, send the hold key
        dprintf("process_record_tap_hold:hold:%X, %X\n", keycode, hook->hold_key);
        return dispatch_key_code(hook->hold_key, record);
    }

    return true; // Not a tap-hold key, continue default processing
}