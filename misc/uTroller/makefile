# Makefile for uTroller

TARGET := utroller

# Source and Include Files
CSOURCES = \
	src/errorHandler.S \
	src/main.S \
	src/system.S \
	../../acb-common/src/stm32f0/startup.S \
	../../acb-common/src/cmsis/m0/core_cm0.S

CINCLUDE_PATHS = \
	-Iinclude \
	-I../../acb-common/include

# Defines
CDEFINES = \
	-DSTM32F042 \
	$(CDEFINES.$(BUILD))

# Build Flags
CPU = cortex-m0

# Linker Flags
LDSCRIPTS = -T ldscripts/mem.ld -T ldscripts/sections.ld

# Include common makefile
include ../../acb-common/makefile.common
