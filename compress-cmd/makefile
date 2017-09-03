TOP = .

# Compiler
CC = gcc

# Compiler flags
CCFLAGS = -I./../huffman -Wall -Wextra -Wall

# Linker flags
LDFLAGS = -L./../huffman/bin -lhuffman

# Files
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

# Directories
TARGET_DIR = $(TOP)/bin
OBJ_DIR = $(TOP)/bin/obj

# Target executable
TARGET = $(TARGET_DIR)/compress-cmd

all: $(TARGET)

# Linking stage
$(TARGET): $(OBJ_DIR)/$(OBJECTS)
	mkdir -p $(TARGET_DIR)
	$(CC) -o $@ $^ $(LDFLAGS) 

# Compile stage
$(OBJ_DIR)/%.o: %.c %.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

# Compile stage
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET_DIR)
