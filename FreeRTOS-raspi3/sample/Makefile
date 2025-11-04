CC := aarch64-none-elf-gcc
CFLAGS := -Wall -O2 -ffreestanding -mcpu=cortex-a53

SRC := sample.c
OBJ := $(SRC:.c=.o)

.PHONY: all clean

all: $(OBJ)

$(OBJ): $(SRC)
	@echo "  CC  $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

