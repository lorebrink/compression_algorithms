CC = gcc
CCFLAGS = -fpic -Wall -Wextra -Wall
LDFLAGS = -shared
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

DEST = ./../bin
TARGET_LIB= $(DEST)/libhuffman.so

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJECTS)
	mkdir -p $(DEST)
	$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f *.o $(TARGET_LIB)
