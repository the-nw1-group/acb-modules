# Makefile for stm32f0 bootloader

TARGET := stm32f0-bootloader

# Source and Include Files
CSOURCES = \
	src/main.S \
	src/startup.S \
	src/bootLoader.S \
	src/applicationRun.S \
	../../acb-common/src/stm32f0/system.S \
	../../acb-common/src/acb/transports/can.S \
	../../acb-common/src/acb/flash.S \
	../../acb-common/src/acb/common.S \
	../../acb-common/src/acb/optionBytes.S \
	../../acb-common/src/cmsis/m0/core_cm0.S

CINCLUDE_PATHS = \
	-Iinclude \
	-I../../acb-common/include

# Defines
CDEFINES = \
	-DSTM32F042 \
	-DHSE_VALUE=8000000 \
	$(CDEFINES.$(BUILD))

# Build Flags
CPU = cortex-m0

# Linker Flags
LDSCRIPTS = -T ldscripts/bootldr-mem.ld -T ldscripts/bootldr-sections.ld

# Include common makefile
include ../../acb-common/makefile.common
