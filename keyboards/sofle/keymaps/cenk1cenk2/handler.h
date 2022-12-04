typedef struct _slave_sleep_state {
    bool power;
} slave_sleep_state;

#ifdef RGBLIGHT_LAYERS

#    define SET_UNDERGLOW(hsv) \
        {0, 6, hsv}, { 36, 6, hsv }
#    define SET_THUMB_CLUSTER(hsv) \
        {25, 2, hsv}, { 36 + 25, 2, hsv }

#endif
