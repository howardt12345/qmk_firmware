# MCU name
MCU = STM32F303

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes       	# Commands for debug and configuration
NKRO_ENABLE = yes	        # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
UNICODE_ENABLE = no         # Unicode
WPM_ENABLE = yes			# Enable words per minute

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    	# Breathing sleep LED during USB suspend
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = IS31FL3731

OLED_ENABLE = yes 		 	# OLED display
OLED_DRIVER = SSD1306 		# Set Driver to SSD1306
ENCODER_ENABLE = yes		# Rotary Encoders

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
