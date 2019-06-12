# Makefile for quad-ir

TARGET := quad-ir

# Source and Include Files
CSOURCES = \
	src/analog.S \
	src/detect.S \
	src/localErrorHandler.S \
	src/irLed.S \
	src/lowPower.S \
	src/main.S \
	src/setup.S \
	src/system.S \
	../../acb-common/src/acb/msCounter.S \
	../../acb-common/src/acb/math.S \
	../../acb-common/src/stm32f0/startup.S \
	../../src/errorHandler.S \
	../../acb-common/src/cmsis/m0/core_cm0.S

CINCLUDE_PATHS = \
	-Iinclude \
	-I../../acb-common/include

# Defines
CDEFINES = \
	-DSTM32F030 \
	$(CDEFINES.$(BUILD))

# Build Flags
CPU = cortex-m0

# Linker Flags
LDSCRIPTS = -T ldscripts/mem.ld -T ldscripts/sections.ld

# Include common makefile
include ../../acb-common/makefile.common
