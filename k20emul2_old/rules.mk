
#DEFAULT_FOLDER=skylupin03/k20emul2

#MCU = STM32F072
MCU = STM32F411

# This file intentionally left blank
#BOARD = GENERIC_STM32_F072XB
BOARD = BLACKPILL_STM32_F401

# Bootloader selection
BOOTLOADER = stm32-dfu

#LAYOUTS = fullsize_iso

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite

MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
LTO_ENABLE = yes

#UNICODE_ENABLE = yes        # Unicode
ENCODER_ENABLE = yes        # Enable Encoder
DIP_SWITCH_ENABLE = yes

OLED_ENABLE = yes
#OLED_DRIVER = SSD1306
#OLED_DRIVER = SH1106

# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = IS31FL3731

LED_MATRIX_ENABLE = yes
LED_MATRIX_DRIVER = IS31FL3731

# EEPROM_DRIVER = transient




