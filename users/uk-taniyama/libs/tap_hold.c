#include "tap_hold.h"

extern const tap_hold_key_t *tap_hold_keys[];
extern const size_t          tap_hold_keys_count;

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
            return true;
        }

        // If held, send the hold key
        if (record->event.pressed) {
            dprintf("process_record_tap_hold:hold:%X, %X\n", keycode, hook->hold_key);
            register_code16(hook->hold_key);
        } else {
            unregister_code16(hook->hold_key);
        }

        return false; // Stop the default LT behavior for hold
    }

    return true; // Not a tap-hold key, continue default processing
}