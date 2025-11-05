# --- Compiler and flags ---
CC := aarch64-none-elf-gcc
CFLAGS := -Wall -O2 -ffreestanding -mcpu=cortex-a53 \
          -I. -I../../../../../porting -Iath9k

# --- Source files (ATH core) ---
ATH_SRC := \
    main.c \
    regd.c \
    hw.c \
    key.c \
    dfs_pattern_detector.c \
    dfs_pri_detector.c

# --- Source files (ATH9K core only — the ones shown in your log) ---
ATH9K_SRC := \
    ath9k/ar9002_hw.c \
    ath9k/ar9003_hw.c \
    ath9k/hw.c \
    ath9k/ar9003_phy.c \
    ath9k/ar9002_phy.c \
    ath9k/ar5008_phy.c \
    ath9k/ar9002_calib.c \
    ath9k/ar9003_calib.c \
    ath9k/calib.c \
    ath9k/eeprom.c \
    ath9k/eeprom_def.c \
    ath9k/eeprom_4k.c \
    ath9k/eeprom_9287.c \
    ath9k/ani.c \
    ath9k/mac.c \
    ath9k/ar9002_mac.c \
    ath9k/ar9003_mac.c \
    ath9k/ar9003_eeprom.c \
    ath9k/ar9003_paprd.c \
    ath9k/ar9003_wow.c \
    ath9k/btcoex.c \
    ath9k/ar9003_mci.c \
    ath9k/ar9003_aic.c \
    ath9k/ar9003_rtt.c \
    ath9k/common.c \
    ath9k/common-init.c \
    ath9k/common-beacon.c \
    ath9k/common-debug.c \
    ath9k/common-spectral.c \
    ath9k/htc_hst.c \
    ath9k/hif_usb.c \
    ath9k/wmi.c \
    ath9k/htc_drv_txrx.c \
    ath9k/htc_drv_main.c \
    ath9k/htc_drv_beacon.c \
    ath9k/htc_drv_init.c \
    ath9k/htc_drv_gpio.c \
    ath9k/htc_drv_debug.c

# --- Combine all sources ---
SRC := $(ATH_SRC) $(ATH9K_SRC)

# --- Object files ---
OBJ := $(SRC:.c=.o)

# --- Output target ---
TARGET := ath_combined.o

# --- Phony targets ---
.PHONY: all clean count

# --- Default target ---
all: $(TARGET)

# --- Link all objects together ---
$(TARGET): $(OBJ)
	@echo "  LD  $@"
	$(CC) -r -o $@ $(OBJ)

# --- Compilation rule ---
%.o: %.c
	@echo "  CC  $<"
	$(CC) $(CFLAGS) -c $< -o $@

# --- Count target ---
count:
	@echo "Total C source files: $(words $(SRC))"
	@echo "Total object files: $(words $(OBJ))"

# --- Clean target ---
clean:
	@echo "  CLEAN"
	rm -f $(OBJ) $(TARGET)

