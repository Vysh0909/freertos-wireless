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

# Main Makefile: Keep this rule and make it a .PHONY target
.PHONY: all clean run runasm wireless_module
all: kernel8.elf

# Ensure the wireless module target is defined before the linking step
wireless_module:
	@echo "==> Building net/wireless module"
	# Explicitly pass the CROSS-compiler prefix down to the sub-make
	$(MAKE) -C net/wireless CC=$(CROSS)-gcc

kernel8.elf : raspberrypi3.ld $(OBJS) wireless_module
	$(CROSS)-gcc -Wl,--build-id=none -std=gnu11 -T raspberrypi3.ld -o $@ -ffreestanding -O2 -nostdlib $(OBJS) $(WIRELESS_OBJS) -lc -lgcc
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

#net/wireless/%o : net/wireless/%.c
#	@echo "==> Building net/wireless module"
#	$(MAKE) -C net/wireless

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

run :
	$(MAKE) kernel8.elf
	qemu-system-aarch64 -M raspi3b -m 1024 -serial null -serial mon:stdio -nographic -kernel kernel8.elf

runasm :
	$(MAKE) kernel8.elf
	qemu-system-aarch64 -M raspi3b -m 1024 -serial null -serial mon:stdio -nographic -kernel kernel8.elf -d in_asm

