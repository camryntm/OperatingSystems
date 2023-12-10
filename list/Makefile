# Makefile for list implementation and test file.

# Compiler settings
CC = gcc
CFLAGS = -Wall -g -std=c99

# Target executable name
TARGET = list

# Source files
SOURCES = list.c main.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Linking the executable from object files
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Compiling source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJECTS)

# Phony targets
.PHONY: all clean
