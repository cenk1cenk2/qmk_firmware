#pragma once

#define EE_HANDS

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100
#define ENCODER_DIRECTION_FLIP

#define FORCE_NKRO
#define NO_ACTION_ONESHOT

#ifdef OLED_ENABLE
#    define OLED_TIMEOUT 60000
#    define SPLIT_OLED_ENABLE
#endif

#define RGB_DI_PIN D3

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_SPLIT
#    define RGBLED_NUM 72 // Number of LEDs
#    define RGBLED_SPLIT \
        { 36, 36 }
#    define RGBLIGHT_DEFAULT_HUE 120
#    define RGBLIGHT_SLEEP
#    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
// #define DRIVER_LED_TOTAL 72
#    define SPLIT_ST7565_ENABLE

#    define RGBLIGHT_LIMIT_VAL 150
#    define RGBLIGHT_HUE_STEP 10
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 17

// enable rgb modes

#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#endif
