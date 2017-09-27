TOP = .

# Compiler
CC = gcc

# Compiler flags
CCFLAGS = -fpic -Wall -Wextra -Wall -std=c99

# Linker flags
LDFLAGS = -shared

# Files
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

# Directories
TARGET_DIR = $(TOP)/bin
OBJ_DIR = $(TOP)/bin/obj

# Target
TARGET_LIB = $(TARGET_DIR)/libhuffman.so

# Full library path
LIB_PATH = ${CURDIR}/bin

all: MAKE_DIRS $(TARGET_LIB)

$(TARGET_LIB): $(OBJ_DIR)/$(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

MAKE_DIRS :
		mkdir -p $(TARGET_DIR)
		mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(TARGET_DIR)