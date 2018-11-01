TOPTARGETS := all clean

SUBDIRS := acb-4tc bootloader/stm32f0-bootloader bootloader/stm32f3-bootloader \
	misc/cbus-network-analyser misc/quad-ir misc/signal-tester misc/uTroller

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)