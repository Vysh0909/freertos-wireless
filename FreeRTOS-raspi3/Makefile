CROSS ?= aarch64-none-elf
CFLAGS =  -mcpu=cortex-a53 -fpic -ffreestanding -std=gnu99 -O2 -Wall -Wextra -I$(INCLUDEPATH1) -I$(INCLUDEPATH2) -I$(INCLUDEPATH3) -I$(INCLUDEPATH4) -I$(INCLUDEPATH5) -I$(INCLUDEPATH6)
ASMFLAGS = -mcpu=cortex-a53
CFLAGS += -Wno-implicit-function-declaration \
          -Wno-int-conversion \
          -Wno-incompatible-pointer-types \
          -Wno-pointer-sign \
          -Wno-unused-variable \
          -Wno-unused-function \
          -Wno-empty-body \
          -Wno-unused-value \
          -Wno-enum-compare \
          -Wno-implicit-int \
          -Wno-missing-declarations \
          -Wno-maybe-uninitialized \
          -Wno-tautological-compare \
          -Wno-discarded-qualifiers \
          -Wno-missing-braces \
	  -Wno-unused-parameter \
	  -Wno-return-type

CFLAGS += -fcommon

BUILDPATH = build
INCLUDEPATH1 ?= FreeRTOS/Source/include
INCLUDEPATH2 ?= FreeRTOS/Source/portable/GCC/ARM_CA53_64_RaspberryPi3
INCLUDEPATH3 ?= Demo
INCLUDEPATH4 ?= FreeRTOS_Plus_Cli
INCLUDEPATH5 ?= Drivers/serial
INCLUDEPATH6 ?= porting


OBJS = build/startup.o 
OBJS +=build/FreeRTOS_asm_vector.o
OBJS +=build/FreeRTOS_tick_config.o
OBJS +=build/uart_string.o
OBJS +=build/uart.o
OBJS +=build/Sample-CLI-commands.o
OBJS +=build/UARTCommandConsole.o
#OBJS +=build/UDP-Related-CLI-commands.o
#OBJS +=build/File-Related-CLI-commands.o
OBJS +=build/FreeRTOS_CLI.o
OBJS +=build/serial.o
OBJS +=build/main.o

OBJS +=build/port.o
OBJS +=build/portASM.o

OBJS +=build/list.o
OBJS +=build/tasks.o
OBJS +=build/queue.o
OBJS +=build/timers.o

OBJS +=build/heap_1.o
OBJS += sample/sample.o

OBJS += build/newlib_stubs.o
OBJS += build/linux_stubs.o
#OBJS += build/linux_stubs_mac80211.o

WIRELESS_OBJS := \
    net/wireless/core.o \
    net/wireless/sysfs.o \
    net/wireless/radiotap.o \
    net/wireless/util.o \
    net/wireless/reg.o \
    net/wireless/scan.o \
    net/wireless/mlme.o \
    net/wireless/ibss.o \
    net/wireless/sme.o \
    net/wireless/chan.o \
    net/wireless/ethtool.o \
    net/wireless/mesh.o \
    net/wireless/ap.o \
    net/wireless/trace.o \
    net/wireless/ocb.o \
    net/wireless/pmsr.o \
    net/wireless/debugfs.o \
    net/wireless/wext-sme.o \
    net/wireless/wext-compat.o \
    net/wireless/nl80211.o

MAC80211_OBJS := \
    net/mac80211/aead_api.o \
    net/mac80211/aes_cmac.o \
    net/mac80211/aes_gmac.o \
    net/mac80211/airtime.o \
    net/mac80211/agg-rx.o \
    net/mac80211/agg-tx.o \
    net/mac80211/chan.o \
    net/mac80211/cfg.o \
    net/mac80211/debugfs.o \
    net/mac80211/debugfs_key.o \
    net/mac80211/debugfs_netdev.o \
    net/mac80211/debugfs_sta.o \
    net/mac80211/driver-ops.o \
    net/mac80211/eht.o \
    net/mac80211/ethtool.o \
    net/mac80211/fils_aead.o \
    net/mac80211/he.o \
    net/mac80211/ht.o \
    net/mac80211/ibss.o \
    net/mac80211/iface.o \
    net/mac80211/key.o \
    net/mac80211/led.o \
    net/mac80211/link.o \
    net/mac80211/main.o \
    net/mac80211/mesh.o \
    net/mac80211/mesh_hwmp.o \
    net/mac80211/mesh_pathtbl.o \
    net/mac80211/mesh_plink.o \
    net/mac80211/mesh_ps.o \
    net/mac80211/mesh_sync.o \
    net/mac80211/michael.o \
    net/mac80211/mlme.o \
    net/mac80211/ocb.o \
    net/mac80211/offchannel.o \
    net/mac80211/parse.o \
    net/mac80211/pm.o \
    net/mac80211/rate.o \
    net/mac80211/rc80211_minstrel_ht.o \
    net/mac80211/rc80211_minstrel_ht_debugfs.o \
    net/mac80211/s1g.o \
    net/mac80211/scan.o \
    net/mac80211/spectmgmt.o \
    net/mac80211/sta_info.o \
    net/mac80211/status.o \
    net/mac80211/rx.o \
    net/mac80211/tdls.o \
    net/mac80211/tkip.o \
    net/mac80211/trace.o \
    net/mac80211/tx.o \
    net/mac80211/util.o \
    net/mac80211/vht.o \
    net/mac80211/wep.o \
    net/mac80211/wme.o \
    net/mac80211/wpa.o \
    net/mac80211/wbrf.o

# Main Makefile: Keep this rule and make it a .PHONY target
.PHONY: all clean run runasm wireless_module mac80211_module
all: kernel8.elf

# Ensure the wireless module target is defined before the linking step
wireless_module:
	@echo "==> Building net/wireless module"
	# Explicitly pass the CROSS-compiler prefix down to the sub-make
	$(MAKE) -C net/wireless CC=$(CROSS)-gcc

mac80211_module:
	@echo "==> Building net/mac80211 module"
	# Explicitly pass the CROSS-compiler prefix down to the sub-make
	$(MAKE) -C net/mac80211 CC=$(CROSS)-gcc


kernel8.elf : raspberrypi3.ld $(OBJS) wireless_module mac80211_module
	$(CROSS)-gcc -Wl,--build-id=none -std=gnu11 -T raspberrypi3.ld -o $@ -ffreestanding -O2 -nostdlib $(OBJS) $(WIRELESS_OBJS) $(MAC80211_OBJS) -lc -lgcc
	$(CROSS)-objdump -D kernel8.elf > kernel8.list

build/%.o : Demo/%.S $(BUILDPATH)
	$(CROSS)-as $(ASMFLAGS) -c -o $@ $<
	
build/%.o : Demo/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/%.o : FreeRTOS_Plus_Cli/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/%.o : Drivers/serial/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/%.o : FreeRTOS/Source/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/%.o : FreeRTOS/Source/portable/GCC/ARM_CA53_64_RaspberryPi3/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/%.o : FreeRTOS/Source/portable/GCC/ARM_CA53_64_RaspberryPi3/%.S
	$(CROSS)-as $(ASMFLAGS) -c -o $@ $<

build/%.o : FreeRTOS/Source/portable/MemMang/%.c
	$(CROSS)-gcc $(CFLAGS)  -c -o $@ $<

build/%.o : porting/src/%.c
	$(CROSS)-gcc $(CFLAGS) -c -o $@ $<

sample/sample.o :
	@echo "==> Building sample module"
	$(MAKE) -C sample

$(BUILDPATH):
	@if [ ! -d $(BUILDPATH) ]; then \
	  echo " mkdir $(BUILDPATH)"; mkdir $(BUILDPATH); \
	fi

clean :
	rm -f build/*.o
	rm -f *.elf
	rm -f *.list
	$(MAKE) -C sample clean
	$(MAKE) -C net/wireless clean
	$(MAKE) -C net/mac80211 clean

run :
	$(MAKE) kernel8.elf
	qemu-system-aarch64 -M raspi3b -m 1024 -serial null -serial mon:stdio -nographic -kernel kernel8.elf

runasm :
	$(MAKE) kernel8.elf
	qemu-system-aarch64 -M raspi3b -m 1024 -serial null -serial mon:stdio -nographic -kernel kernel8.elf -d in_asm

