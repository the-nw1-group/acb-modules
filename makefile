TOPTARGETS := all clean

SUBDIRS := \
	bootloader\stm32l431-bootloader \
	misc/quad-ir misc/signal-tester misc/uTroller misc/acb-20-devboard

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)