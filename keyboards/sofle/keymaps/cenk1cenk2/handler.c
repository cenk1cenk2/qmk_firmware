#include QMK_KEYBOARD_H
#include "transactions.h"
#include "handler.h"

bool power = false;

void suspend_wakeup_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable();
#endif
#ifdef OLED_ENABLE
    oled_on();
#endif

    power = true;

    if (!is_keyboard_master()) return;

    slave_sleep_state m2s = {power = power};
    transaction_rpc_send(USER_SYNC_A, sizeof(m2s), &m2s);
}

void suspend_power_down_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_disable();
#endif
#ifdef OLED_ENABLE
    oled_off();
#endif

    power = false;

    if (!is_keyboard_master()) return;

    slave_sleep_state m2s = {power = power};
    transaction_rpc_send(USER_SYNC_A, sizeof(m2s), &m2s);
}

void user_sync_a_slave_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
    const slave_sleep_state *m2s = (const slave_sleep_state *)in_data;

    power = m2s->power;

    if (!power) {
#ifdef RGBLIGHT_ENABLE
        rgblight_disable();
#endif
#ifdef OLED_ENABLE
        oled_off();
#endif
    } else {
#ifdef RGBLIGHT_ENABLE
        rgblight_enable();
#endif
#ifdef OLED_ENABLE
        oled_on();
#endif
    }
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(USER_SYNC_A, user_sync_a_slave_handler);

#ifdef RGBLIGHT_LAYERS
    rgblight_layers = rgb_layers;
#endif
}
