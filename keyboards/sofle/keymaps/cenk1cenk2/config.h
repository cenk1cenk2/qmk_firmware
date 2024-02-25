#pragma once

#define EE_HANDS

#ifndef NO_DEBUG
#    define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#    define NO_PRINT
#endif // !NO_PRINT

#define DISABLE_LEADER

#define ENCODER_DIRECTION_FLIP

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT

#define AUTO_SHIFT_TIMEOUT 200
#define AUTO_SHIFT_REPEAT
#define NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_NUMERIC

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#define FORCE_NKRO

#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_SLEEP_STATE

#ifdef OLED_ENABLE
#    define OLED_TIMEOUT 60000
#    define SPLIT_OLED_ENABLE
#endif

#define WS2812_DI_PIN D3

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_SPLIT
#    define RGBLED_NUM 72 // Number of LEDs
#    define RGBLED_SPLIT \
        { 36, 36 }
#    define RGBLIGHT_DEFAULT_HUE 120
#    define RGBLIGHT_SLEEP
#    define RGB_DISABLE_WHEN_USB_SUSPENDED

#    define RGBLIGHT_LIMIT_VAL 150
#    define RGBLIGHT_HUE_STEP 10
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 17

#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT

#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_LAYERS_RETAIN_VAL
#    define SPLIT_LAYER_STATE_ENABLE
#endif
