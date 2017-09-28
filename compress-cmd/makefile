TOP = .

# Compiler
CC = g++

# Compiler flags
CCFLAGS = -I./../huffman -Wall -Wextra -Wall -Werror -pedantic -std=c++11

# Linker flags
LDFLAGS = -L./../huffman/bin -lhuffman

# Directories
TARGET_DIR = $(TOP)/bin
OBJ_DIR = $(TOP)/bin/obj

# Files
SOURCES = $(wildcard *.cc)
OBJECTS = $(SOURCES:%.cc=$(OBJ_DIR)/%.o)

# Target executable
TARGET = $(TARGET_DIR)/compress-cmd

all: $(TARGET)

# Linking stage
$(TARGET): $(OBJECTS)
	mkdir -p $(TARGET_DIR)
	$(CC) -o $@ $^ $(LDFLAGS) 

# Compile stage
$(OBJ_DIR)/%.o: %.cc %.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

# Compile stage
$(OBJ_DIR)/%.o: %.cc
	mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET_DIR)
