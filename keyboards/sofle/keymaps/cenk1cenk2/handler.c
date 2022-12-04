#include QMK_KEYBOARD_H
#include "transactions.h"
#include "handler.h"

void suspend_power_down_user(void) {
    oled_off();
    rgblight_disable();

    if (!is_keyboard_master()) return;

    slave_sleep_state m2s = {};
    transaction_rpc_send(USER_SYNC_A, sizeof(m2s), &m2s);
}

void suspend_wakeup_init_user(void) {
    rgblight_enable();
    oled_scroll_off();
    oled_on();
}

void user_sync_a_slave_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
#ifdef RGBLIGHT_ENABLE
    rgblight_disable();
#endif
#ifdef OLED_ENABLE
    oled_scroll_left();
    oled_clear();
    oled_off();
#endif
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(USER_SYNC_A, user_sync_a_slave_handler);

#ifdef RGBLIGHT_LAYERS
    rgblight_layers = rgb_layers;
#endif
}
