# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
LTO_ENABLE = yes			# Link time optimization
BOOTMAGIC_ENABLE = no		# Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes		# Mouse keys
EXTRAKEY_ENABLE = yes		# Audio control and System control
CONSOLE_ENABLE = no			# Console for debug
COMMAND_ENABLE = no       	# Commands for debug and configuration
NKRO_ENABLE = yes			# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
UNICODE_ENABLE = no         # Unicode

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    	# Breathing sleep LED during USB suspend
RGB_MATRIX_ENABLE = yes 	# Enable RGB matrix
RGB_MATRIX_DRIVER = WS2812

OLED_ENABLE = yes 		 	# OLED display
OLED_DRIVER = SSD1306 		# Set Driver to SSD1306
ENCODER_ENABLE = yes		# Rotary Encoders
