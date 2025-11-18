# --- Compiler and flags ---
CC:= aarch64-none-elf-gcc
CFLAGS := -Wall -O2 -ffreestanding -mcpu=cortex-a53 -I -Itests -I../../porting
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
	  -Wno-missing-braces

CFLAGS += -DCONFIG_CFG80211
# --- Source files ---
SRC := \
	core.c sysfs.c radiotap.c util.c reg.c scan.c mlme.c ibss.c sme.c \
	chan.c ethtool.c mesh.c ap.c trace.c ocb.c pmsr.c debugfs.c wext-sme.c wext-compat.c nl80211.c


# --- Object files ---
OBJ := $(SRC:.c=.o)

# --- Quiet build control ---
Q ?= @
ifeq ($(V),1)
  Q :=
endif

# --- Phony targets ---
.PHONY: all clean

# --- Default target ---
all: $(OBJ)

# --- Compilation rule ---
%.o: %.c
	@echo "  CC  $<"
	$(Q)$(CC) $(CFLAGS) -c $< -o $@

# --- Clean target ---
clean:
	@echo "Cleaning..."
	$(Q)rm -f $(OBJ)
