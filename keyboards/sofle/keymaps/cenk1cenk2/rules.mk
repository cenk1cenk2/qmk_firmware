LTO_ENABLE = yes
BOOTMAGIC_ENABLE = no
CONSOLE_ENABLE = no

SPACE_CADET_ENABLE = no
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes

RGBLIGHT_ENABLE = yes
OLED_ENABLE = yes
ENCODER_ENABLE = yes
NKRO_ENABLE = yes

VIA_ENABLE = yes

SRC +=  ./oled.c \
        ./handler.c \
        ./rgb.c
