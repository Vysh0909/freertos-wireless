# --- Compiler and flags ---
CC := aarch64-none-elf-gcc
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
          -Wno-missing-braces \
	  -Wno-return-type \
          -Wno-unused-but-set-variable \
	  -Wno-address-of-packed-member \
	  -Wno-format-overflow -Wno-format-truncation -Wno-format  -Wno-uninitialized 

CFLAGS += -DCONFIG_MAC80211_DEBUGFS \
	  -DCONFIG_MAC80211_LEDS \
	  -DCONFIG_MAC80211_MESH \
	  -DCONFIG_MAC80211_RC_MINSTREL
CFLAGS += -fcommon

# --- Source files ---
SRC := \
        aead_api.c \
        aes_cmac.c \
        aes_gmac.c \
        airtime.c \
        agg-rx.c \
        agg-tx.c \
        chan.c \
        cfg.c \
        debugfs.c \
        debugfs_key.c \
        debugfs_netdev.c \
        debugfs_sta.c \
        driver-ops.c \
        eht.c \
        ethtool.c \
        fils_aead.c \
        he.c \
        ht.c \
        ibss.c \
        iface.c \
        key.c \
        led.c \
        link.c \
        main.c \
        mesh.c \
        mesh_hwmp.c \
        mesh_pathtbl.c \
        mesh_plink.c \
        mesh_ps.c \
        mesh_sync.c \
        michael.c \
	mlme.c \
        ocb.c \
        offchannel.c \
        parse.c \
        pm.c \
        rate.c \
        rc80211_minstrel_ht.c \
        rc80211_minstrel_ht_debugfs.c \
        s1g.c \
        scan.c \
        spectmgmt.c \
	sta_info.c \
	status.c \
	rx.c \
        tdls.c \
        tkip.c \
        trace.c \
        tx.c \
        util.c \
        vht.c \
        wep.c \
        wme.c \
        wpa.c \
        wbrf.c 

# --- Object files ---
OBJ := $(SRC:.c=.o)

# --- Phony targets ---
.PHONY: all clean

# --- Quiet build control ---
Q ?= @
ifeq ($(V),1)
  Q :=
endif

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
