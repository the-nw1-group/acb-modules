# Makefile for cbus-network-analyser

TARGET := cbus-network-analyser

# Source and Include Files
CSOURCES = \
	src/canMessageLog.S \
	src/errorHandler.S \
	src/ledPwm.S \
	src/main.S \
	src/random.S \
	src/rotaryEncoder.S \
	src/setup.S \
	src/fsm/fsmActivityGraph.S \
	src/fsm/fsmCommon.S \
	src/fsm/fsmStatistics.S \
	src/fsm/fsmTabs.S \
	src/fsm/filter/fsmFilterCanActivity.S \
	src/fsm/filter/fsmFilterScreenSaver.S \
	src/images/graph.S \
	src/images/graph_s.S \
	src/images/log.S \
	src/images/log_s.S \
	src/images/msg.S \
	src/images/msg_s.S \
	src/images/splash.S \
	src/images/stat.S \
	src/images/stat_s.S \
	src/images/tx.S \
	src/images/tx_s.S \
	../../acb-common/src/acb/math.S \
	../../acb-common/src/acb/watchdog.S \
	../../acb-common/src/acb/simpleInputDebounce.S \
	../../acb-common/src/acb/flash.S \
	../../acb-common/src/cbus/src/cbusMessages.S \
	../../acb-common/src/acb/optionBytes.S \
	../../acb-common/src/acb/transports/can.S \
	../../acb-common/src/acb/display/display.S \
	../../acb-common/src/acb/display/smallFont.S \
	../../acb-common/src/acb/display/ssd1306.S \
	../../acb-common/src/acb/display/displayDriverSPI.S \
	../../acb-common/src/acb/msCounter.S \
	../../acb-common/src/stm32f0/startup.S \
	../../acb-common/src/stm32f0/system.S \
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
