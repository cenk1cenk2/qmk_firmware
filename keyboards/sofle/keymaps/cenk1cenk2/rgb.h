#ifdef RGBLIGHT_LAYERS

#    define SET_UNDERGLOW(hsv) \
        {0, 6, hsv}, { 35, 6, hsv }
#    define SET_THUMB_CLUSTER(hsv) \
        {25, 2, hsv}, { 35 + 25, 2, hsv }
#    define SET_LAYER_ID(hsv) \
        {0, 1, hsv}, {35 + 0, 1, hsv}, {1, 6, hsv}, {35 + 1, 6, hsv}, {7, 4, hsv}, {35 + 7, 4, hsv}, {25, 2, hsv}, { 35 + 25, 2, hsv }
#endif
