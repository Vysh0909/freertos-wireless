# --- Compiler and flags ---
CC := aarch64-none-elf-gcc
CFLAGS := -Wall -O2 -ffreestanding -mcpu=cortex-a53 -I -Itests -I../../porting

# --- Source files ---
SRC := \
	core.c sysfs.c radiotap.c util.c reg.c scan.c nl80211.c mlme.c ibss.c sme.c \
	chan.c ethtool.c mesh.c ap.c trace.c ocb.c pmsr.c debugfs.c wext-compat.c wext-sme.c \
	certs/shipped-certs.c


# --- Object files ---
OBJ := $(SRC:.c=.o)

# --- Phony targets ---
.PHONY: all clean

# --- Default target ---
all: $(OBJ)

# --- Compilation rule ---
$(OBJ): %.o: %.c
	@echo "  CC  $<"
	$(CC) $(CFLAGS) -c $< -o $@

# --- Clean target ---
clean:
	rm -f $(OBJ)

