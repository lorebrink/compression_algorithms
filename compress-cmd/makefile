# Compiler
CC=gcc

# Flags
CCFLAGS = -Wall -Wextra -Wall -I./../huffman
LDFLAGS = -L/home/lukas/projects/compression_algorithms/bin -l huffman

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

DEST = ./../bin
TARGET=$(DEST)/compress-cmd

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(DEST)
	$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
