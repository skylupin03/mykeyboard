# Default to K310 variant, since it will also work on a K320
# DEFAULT_FOLDER=skylupin03/tauchef2/k310led     -last

# MCU name
# Actually F070, but close enough

MCU = STM32F072

BOARD = DURGOD_STM32_F070

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700) 
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
LTO_ENABLE = yes

DYNAMIC_MACRO_ENABLE = yes
WPM_ENABLE = yes

TAP_DANCE_ENABLE = yes      # Tappa Dance

#OLED_ENABLE = yes
##OLED_DRIVER = SSD1306

##LAYOUTS = fullsize_iso				
LAYOUTS = fullsize_ansi fullsize_iso

##ENCODER_ENABLE = yes        # Enable Encoder
##DIP_SWITCH_ENABLE = yes

##RGB_MATRIX_ENABLE = yes
##RGB_MATRIX_DRIVER = IS31FL3731

#LED_MATRIX_ENABLE = yes
#LED_MATRIX_DRIVER = IS31FL3731

##EEPROM_DRIVER = transient