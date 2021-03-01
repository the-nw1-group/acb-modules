TOPTARGETS := all clean

SUBDIRS := acb-4tc \
	bootloader/stm32f0-bootloader bootloader/stm32f3-bootloader bootloader\stm32l431-bootloader \
	misc/cbus-network-analyser misc/quad-ir misc/signal-tester misc/uTroller misc/acb-20-devboard

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)