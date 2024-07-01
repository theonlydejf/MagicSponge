ARDUINO_DIR   = /Applications/Arduino.app/Contents/Java
ARDMK_DIR     = ~/repos/Arduino-Makefile
AVR_TOOLS_DIR = ~/.avr
MONITOR_PORT  = /dev/tty.usb*
OBJDIR = bin
SOURCE_FOLDERS = ../ ../ard-src ../display
# TODO add include folder
BOARD_TAG = uno
BOARD_SUB = atmega328
ARDUINO_LIBS =

CXXFLAGS += -DDEBUG

CWD_HEADERS_SRCS = $(wildcard $(addsuffix /*.h, $(SOURCE_FOLDERS)))
CWD_HEADERS = $(notdir $(CWD_HEADERS_SRCS))

LOCAL_CPP_SRCS = $(wildcard $(addsuffix /*.cpp, $(SOURCE_FOLDERS)))

.PHONY: init_headers all cleanup_headers
build: init_headers all cleanup_headers

include $(ARDMK_DIR)/Arduino.mk

init_headers:
	@echo ====== Preparing headers ======
	$(foreach file, $(CWD_HEADERS_SRCS), echo Copying $(file); cp $(file) ./;)

cleanup_headers:
	@echo ====== Cleaning headers ======
	$(foreach file, $(CWD_HEADERS), echo Deleting $(file); rm -f $(file);)

