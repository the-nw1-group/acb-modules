# Makefile for uTroller

TARGET := utroller

# Source and Include Files
CSOURCES = \
	src/analog.S \
	src/configuration.S \
	src/localErrorHandler.S \
	src/main.S \
	src/setup.S \
	src/system.S \
	src/drv8816.S \
	src/controller.S \
	../acb-common-m0/src/stm32f0/startup.S \
	../acb-common-m0/src/acb/msCounter.S \
	../acb-common-m0/src/acb/math.S \
	../acb-common-m0/src/cmsis/m0/core_cm0.S \
	../acb-common-m0/src/acb/flash.S \
	../acb-common-m0/src/acb/errorHandler.S

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
