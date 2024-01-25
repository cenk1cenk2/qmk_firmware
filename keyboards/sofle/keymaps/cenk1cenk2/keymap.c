#include QMK_KEYBOARD_H
#include "layers.h"

enum my_keycodes { KC_QWERTY = SAFE_RANGE, KC_LOWER, KC_RAISE, KC_ADJUST, KC_PRVWD, KC_NXTWD, KC_DLINE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
QK_GESC,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,        KC_7,      KC_8,      KC_9,       KC_0,        KC_BSPC,
KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                               KC_Y,        KC_U,      KC_I,      KC_O,       KC_P,        KC_MINS,
KC_LCTL,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                               KC_H,        KC_J,      KC_K,      KC_L,       KC_SCLN,     KC_QUOT,
KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_MUTE,    RGB_TOG,    KC_N,        KC_M,      KC_COMM,   KC_DOT,     KC_SLSH,     KC_RSFT,
              KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LOWER,   KC_ENT,                     KC_SPC,     KC_RAISE,    KC_RCTL,    KC_RALT,   KC_RGUI
),
[_LOWER]  = LAYOUT(
KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
KC_TRNS,    KC_LCBR,    KC_RCBR,    KC_LBRC,    KC_RBRC,    KC_NO,                              KC_F12,     KC_LCBR,    KC_RCBR,    KC_LBRC,    KC_RBRC,    KC_EQL,
KC_TRNS,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                            KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_BSLS,
KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_MPLY,    KC_TRNS,    KC_PLUS,    KC_PIPE,    KC_LT,      KC_GT,      KC_QUES,    KC_TRNS,
              KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
),
[_RAISE]  = LAYOUT(
KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_PSCR,                            KC_PGUP,    KC_PRVWD,   KC_UP,      KC_NXTWD,   KC_DLINE,   KC_DEL,
KC_TRNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                              KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO,      KC_ENT,
KC_TRNS,    KC_UNDO,    KC_CUT,     KC_COPY,    KC_PASTE,   KC_NO,      KC_TRNS,    KC_TRNS,    KC_NO,      KC_HOME,    KC_NO,      KC_END,     KC_NO,      KC_TRNS,
              KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
),
[_ADJUST] = LAYOUT(
QK_REBOOT,  KC_NO,      KC_NO,      KC_NO,      RGB_RMOD,   RGB_MOD,                            KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
KC_NO,      KC_CAPS,    KC_INS,     KC_SCRL,    CG_TOGG,    KC_NO,                              KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
KC_NO,      RGB_HUI,    RGB_SAI,    RGB_VAI,    KC_NO,      KC_NO,                              KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
KC_NO,      RGB_HUD,    RGB_SAD,    RGB_VAD,    KC_NO,      KC_NO,      KC_TRNS,    KC_TRNS,    KC_NO,      KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_NO,      KC_NO,
              KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
)
};

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QWERTY:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
            }
            break;
        case _RAISE:
        case _LOWER:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_MS_WH_RIGHT);
                } else {
                    tap_code(KC_MS_WH_LEFT);
                }
            }
            break;
    }

    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            // custom layers
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;

            // custom keycodes
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
    }
    return true;
}
