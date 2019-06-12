# Makefile for stm32f3 bootloader

TARGET := stm32f3-bootloader

# Source and Include Files
CSOURCES = \
	src/main.S \
	src/startup.S \
	src/bootLoader.S \
	src/applicationRun.S \
	../../acb-common/src/stm32f30/system.S \
	../../acb-common/src/acb/transports/can.S \
	../../acb-common/src/acb/flash.S \
	../../acb-common/src/acb/common.S \
	../../acb-common/src/acb/optionBytes.S \
	../../acb-common/src/cmsis/m4/core_cm4.S

CINCLUDE_PATHS = \
	-Iinclude \
	-I../../acb-common/include

# Defines
CDEFINES = \
	-DSTM32F303 \
	-DHSE_VALUE=8000000 \
	$(CDEFINES.$(BUILD))

# Build Flags
CPU = cortex-m3
FLOAT_ABI = -mfloat-abi=hard
FPU = -mfpu=fpv4-sp-d16 $(FLOAT_ABI)

# Linker Flags
LDSCRIPTS = -T ldscripts/bootldr-mem.ld -T ldscripts/bootldr-sections.ld

# Include common makefile
include ../../acb-common/makefile.common
