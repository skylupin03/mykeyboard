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

AUDIO_ENABLE = no           # Audio output
LTO_ENABLE = yes

#UNICODE_ENABLE = yes        # Unicode
ENCODER_ENABLE = yes        # Enable Encoder
DIP_SWITCH_ENABLE = yes

OLED_ENABLE = yes
#OLED_DRIVER = SSD1306		# default값이라 필요없는듯

BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality
BACKLIGHT_DRIVER = pwm	     # pwm, software, custom or no

RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow (WS2811, WS2812, WS2812B, WS2812C, SK6812, SK6812MINI, SK6805, APA102)
WS2812_DRIVER = spi			# bitbang, spi(circular buffer issue), pwm(too much access, Noise도 심한듯)

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812	# IS31FL3731, 3733, 3737, WS2812등등

# RGB layout selection
#RGB_ENCODERS = yes # For RGB encoders, solder on both WS2811 chips
#STAGGERED_LAYOUT = no # If you soldered R1-A12 and R4-A12, enable this.

#LED_MATRIX_ENABLE = yes
LED_MATRIX_DRIVER = IS31FL3731

# EEPROM_DRIVER = transient

#간간히 OLED가 동작안하는 문제 해결?
ISSI_ENABLE = yes			# If the I2C pullup resistors aren't install this must be disabled

#WATCHDOG_ENABLE = no		# Resets keyboard if matrix_scan isn't run every 250ms//
