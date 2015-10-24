# ################################################################################
# # Project Settings


PROJECT_BASE_PATH = /home/marvin/git/private/
PROJECT_BASE_NAME = airdryer_controller

PROJECT_DIR				= $(PROJECT_BASE_PATH)$(PROJECT_BASE_NAME)
ARDMK_DIR         = /home/marvin/git/private/Arduino-Makefile
ARDUINO_DIR       = /home/marvin/git/private/arduino-1.6.5-r5
BOOTLOADER_PARENT = /home/marvin/git/private/arduino-1.6.5-r5/hardware/arduino/avr/bootloaders
AVRDUDE 	  			= /usr/bin/avrdude
AVRDUDE_CONF 	  	= /etc/avrdude.conf

BOARD_TAG	  			= pro
BOARD_SUB         = 16MHzatmega168
#MCU		  				= atmega168
#F_CPU		  			= 16000000L
MONITOR_PORT	  	= /dev/ttyUSB*
ISP_PROG 	  			= usbasp


USER_LIB_PATH     :=  $(PROJECT_DIR)/lib
OBJDIR            = $(PROJECT_DIR)/build


include $(ARDMK_DIR)/Arduino.mk
