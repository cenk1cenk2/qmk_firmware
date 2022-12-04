#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum my_keycodes { KC_QWERTY = SAFE_RANGE, KC_LOWER, KC_RAISE, KC_ADJUST, KC_PRVWD, KC_NXTWD, KC_LSTRT, KC_LEND, KC_DLINE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_QWERTY] = LAYOUT(QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, RGB_TOG, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, KC_LALT, KC_LCTL, KC_LOWER, KC_ENT, KC_SPC, KC_RAISE, KC_RCTL, KC_RALT, KC_RGUI),
                                                              [_LOWER]  = LAYOUT(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_NO, KC_F12, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_EQL, KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_TRNS, KC_PLUS, KC_PIPE, KC_LT, KC_GT, KC_QUES, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [_RAISE]  = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_PGUP, KC_PRVWD, KC_UP, KC_NXTWD, KC_DLINE, KC_DEL, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_ENT, KC_TRNS, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_LSTRT, KC_NO, KC_LEND, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [_ADJUST] = LAYOUT(QK_REBOOT, KC_NO, KC_NO, KC_NO, RGB_RMOD, RGB_MOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_CAPS, KC_INS, KC_SCRL, CG_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,   0,   0,   0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,  0,   0,   0,   0,   0,   0,  0, 0,   0,   0,   0,   0,  0,  0, 0, 0, 0, 0,   0,   0,   0,   0, 0, 0, 0, 0,   0,   0,   0,   0, 0, 0, 0,   0,   0, 0, 0, 0, 0,  0,  0,  0,   0,   0,   0,   0,   0,   0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,  0,   0,   0,  0,   0,  0,  0,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,  0,  0, 0, 0, 0, 0,   0,   248, 252, 142, 135, 3,  3,   123, 127, 14,  0,   0,   0,   128, 128, 128, 128, 0,  0,   128, 224, 248, 124, 118, 31,  15,  195, 240, 252, 238, 63,  15,  128, 128, 128, 128,
        128, 0,   0,   0,  0,  0,   0,   24,  60,  142, 243, 255, 239, 96, 48,  56, 28, 15,  7,   0,   128, 128, 128, 128, 128, 0,  0,  0,   0,   0,   0,   0,   0,  0, 192, 240, 252, 254, 63, 15, 0, 0, 0, 0, 128, 128, 128, 128, 0, 0, 0, 0, 128, 128, 128, 128, 0, 0, 0, 128, 192, 0, 0, 0, 0, 0,  0,  0,  128, 128, 128, 128, 224, 252, 62, 15, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 248, 252, 132, 129, 131, 131, 135, 207, 254, 124, 96, 252, 254, 198, 255, 121, 63, 55, 248, 252, 31, 255, 24, 24, 24, 120, 255, 223, 195, 97, 120, 252, 255, 223, 205, 207, 103, 51, 24, 0, 0, 0, 0, 128, 224, 252, 63,  7,   15,  28, 120, 240, 224, 192, 240, 252, 255, 223, 205, 207, 103, 51, 124, 127, 103, 240, 248, 254, 222, 120, 255, 255, 131, 223, 246, 126, 60,  112, 252, 254,
        198, 255, 121, 63, 55, 248, 252, 222, 199, 99,  249, 253, 223, 99, 112, 28, 15, 251, 255, 222, 192, 240, 252, 254, 199, 99, 49, 253, 255, 199, 192, 112, 24, 0, 0,   0,   0,   0,   0,  0,  0, 0, 0, 0, 0,   0,   0,   0,   0, 1, 1, 1, 1,   1,   1,   1,   0, 0, 0, 0,   0,   0, 0, 0, 0, 31, 31, 27, 15,  7,   0,   0,   0,   0,   0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  1,   1,   0,   0,   0,   0,   0,   0,   0,   1,   1,  1,   0,   0,   0,   0,   0,  0,  28,  30,  26, 31,  15, 3,  0,  0,   0,   1,   1,   1,  1,   0,   0,   0,   0,   0,   0,   0,  0,  0, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    };

    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Norm"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }

    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }

    return false;
}

void suspend_power_down_user(void) {
    oled_off();
    rgblight_disable();
}

void suspend_wakeup_init_user(void) {
    oled_on();
    rgblight_enable();
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
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
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
                    tap_code(KC_MS_WH_DOWN);
                } else {
                    tap_code(KC_MS_WH_UP);
                }
            }
            break;
        case _LOWER:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_MPRV);
                } else {
                    tap_code(KC_MNXT);
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_MS_WH_LEFT);
                } else {
                    tap_code(KC_MS_WH_RIGHT);
                }
            }
            break;
    }

    return false;
}

#endif
