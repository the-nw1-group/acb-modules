# Makefile for acb-4tc

TARGET := acb-4tc

# Source and Include Files
CSOURCES = \
	src/main.S \
	src/setup.S \
	../acb-common/src/acb/common.S \
	../acb-common/src/acb/msCounter.S \
	../acb-common/src/acb/math.S \
	../acb-common/src/acb/flash.S \
	../acb-common/src/acb/optionBytes.S \
	../acb-common/src/acb/configurationManager.S \
	../acb-common/src/acb/transports/can.S \
	../acb-common/src/acb/eeprom/eeprom.S \
	../acb-common/src/acb/eeprom/eepromCache.S \
	../acb-common/src/acb/eeprom/eepromI2C.S \
	../acb-common/src/cbus/src/cbusModuleParameters.S \
	../acb-common/src/cbus/src/cbusMessages.S \
	../acb-common/src/stm32f0/startup.S \
	../acb-common/src/stm32f0/system.S \
	../acb-common/src/cmsis/m0/core_cm0.S

CINCLUDE_PATHS = \
	-Iinclude \
	-I../acb-common/include

# Defines
CDEFINES = \
	-DSTM32F042 \
	$(CDEFINES.$(BUILD))

# Build Flags
CPU = cortex-m0

# Linker Flags
LDSCRIPTS = -T ../acb-common/ldscripts/m0/f32r6-acb-module-mem.ld -T ../acb-common/ldscripts/m0/acb-module-sections.ld

# Include common makefile
include ../acb-common/makefile.common
