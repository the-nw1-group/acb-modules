# Makefile for stm32l431 bootloader

TARGET := stm32l431-bootloader

# Source and Include Files
CSOURCES = \
	src/main.S \
 	src/bootLoader.S \
	src/startup.S \
	src/applicationRun.S \
	../../acb-common/src/stm32l431/system.S \
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
	-DSTM32L431xx \
 	-DHSE_VALUE=12000000\
	$(CDEFINES.$(BUILD))

# Build Flags
CPU = cortex-m4
FLOAT-ABI = -mfloat-abi=hard
FPU = -mfpu=fpv4-sp-d16

# Linker Flags
LDSCRIPTS = -T ldscripts/bootldr-mem.ld -T ldscripts/bootldr-sections.ld

# Include common makefile
include ../../acb-common/makefile.common
