# Makefile for signal-tester

TARGET := signal-tester

# Source and Include Files
CSOURCES = \
	src/analog.S \
	src/configuration.S \
	src/localErrorHandler.S \
	src/main.S \
	src/setup.S \
	src/system.S \
	src/fsm/fsmAspectTest.S \
	src/fsm/fsmCommon.S \
	src/fsm/fsmConfigDelete.S \
	src/fsm/fsmConfigView.S \
	src/fsm/fsmHelp.S \
	src/fsm/fsmMenus.S \
	src/fsm/fsmPwmSetup.S \
	src/fsm/fsmServoSave.S \
	src/fsm/fsmServoSetup.S \
	src/fsm/fsmSignalSave.S \
	src/fsm/fsmSignalSetup.S \
	src/fsm/fsmWhiteTest.S \
	../acb-common-m0/src/stm32f0/startup.S \
	../acb-common-m0/src/acb/msCounter.S \
	../acb-common-m0/src/acb/math.S \
	../acb-common-m0/src/acb/watchdog.S \
	../acb-common-m0/src/acb/simpleInputDebounce.S \
	../acb-common-m0/src/acb/ws2812.S \
	../acb-common-m0/src/acb/display/display.S \
	../acb-common-m0/src/acb/display/font.S \
	../acb-common-m0/src/acb/display/ssd1306.S \
	../acb-common-m0/src/acb/display/displayDriverI2C.S \
	../acb-common-m0/src/acb/eeprom/eeprom.S \
	../acb-common-m0/src/acb/eeprom/eepromCache.S \
	../acb-common-m0/src/acb/eeprom/eepromI2C.S \
	../acb-common-m0/src/errorHandler.S \
	../acb-common-m0/src/cmsis/m0/core_cm0.S

CINCLUDE_PATHS = \
	-Iinclude \
	-I../acb-common-m0/include

# Defines
CDEFINES = \
	-DSTM32F042 \
	$(CDEFINES.$(BUILD))

# Build Flags
CPU = cortex-m0

# Linker Flags
LDSCRIPTS = -T ldscripts/mem.ld -T ldscripts/sections.ld

# Include common makefile
include ../acb-common-m0/makefile.common
