#include QMK_KEYBOARD_H
#include "transactions.h"
#include "handler.h"
#include "layers.h"

void suspend_wakeup_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable();
#endif
#ifdef OLED_ENABLE
    oled_on();
#endif

    if (!is_keyboard_master()) return;
    slave_sleep_state m2s = {power : true};
    transaction_rpc_send(USER_SYNC_SLEEP_STATE, sizeof(m2s), &m2s);
}

void suspend_power_down_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_disable_noeeprom();
#endif
#ifdef OLED_ENABLE
    oled_clear();
    oled_off();
#endif

    if (!is_keyboard_master()) return;
    slave_sleep_state m2s = {power : false};
    transaction_rpc_send(USER_SYNC_SLEEP_STATE, sizeof(m2s), &m2s);
}

void user_sync_sleep_state_slave_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
    const slave_sleep_state *m2s = (const slave_sleep_state *)in_data;

    switch (m2s->power) {
        case true:
#ifdef RGBLIGHT_ENABLE
            rgblight_enable();
#endif
#ifdef OLED_ENABLE
            oled_set_brightness(255);
            oled_on();
#endif
            break;
        case false:
#ifdef RGBLIGHT_ENABLE
            rgblight_disable_noeeprom();
#endif
#ifdef OLED_ENABLE
            oled_set_brightness(0);
            // oled_clear();
            // oled_off();
#endif
            break;
    }
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(USER_SYNC_SLEEP_STATE, user_sync_sleep_state_slave_handler);
}
