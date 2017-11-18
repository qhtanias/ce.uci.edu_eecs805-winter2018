# GCC compiler
#    -g: with debug options
#    -Wall: all warnings enabled
#    -Werror: turn warning into errors
#    -std=gnu89: Use GNU89 standard
GCC := gcc -g -Wall -Werror -std=gnu89

RM := rm
MKDIR := mkdir -p
OUT_DIR := bld

.PHONY: directories

all: directories $(OUT_DIR)/hw.exe

directories: $(OUT_DIR)

$(OUT_DIR):
	$(MKDIR) $@

clean:
	$(RM) -rf $(OUT_DIR)

$(OUT_DIR)/hw.exe: $(OUT_DIR)/main.o
	$(GCC) -o $@ $<

$(OUT_DIR)/main.o: main.c
	$(GCC) -c -o $@ $<

