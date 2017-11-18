# GCC compiler
#    -g: with debug options
#    -Wall: all warnings enabled
#    -Werror: turn warning into errors
CC := gcc
CFLAGS := -g -Wall -Werror

#
# Commands
#
RM := rm
MKDIR := mkdir -p
OUT_DIR := bld
OBJ_DIR := $(OUT_DIR)/obj

#
# Source Files
#
SOURCES := main.c \
	bits.c

#
# Object Files
#
OBJECTS := $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

#
# Build Target
#
TARGET := $(OUT_DIR)/lab

#
# Rules
#
.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) -rf $(OUT_DIR)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

