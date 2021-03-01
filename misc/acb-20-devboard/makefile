# Makefile for uTroller

TARGET := acb_20_devboard

# Source and Include Files
CSOURCES = \
	../../acb-common/src/stm32l431/system.S \
	../../acb-common/src/stm32l431/startup.S \
	../../acb-common/src/acb/msCounter.S \
	../../acb-common/src/cmsis/m4/core_cm4.S \
	../../acb-common/src/acb/errorHandler.S \
	src/main.S

CINCLUDE_PATHS = \
	-Iinclude \
	-I../../acb-common/include

# Defines
CDEFINES = \
	-DSTM32L431xx \
 	-DHSE_VALUE=12000000\
	$(CDEFINES.$(BUILD))

# Build Flags
CPU = cortex-m4
FPU = -mfpu=fpv4-sp-d16
FLOAT-ABI = -mfloat-abi=hard

# Linker Flags
LDSCRIPTS = -T ldscripts/mem.ld -T ldscripts/sections.ld

# Include common makefile
include ../../acb-common/makefile.common
