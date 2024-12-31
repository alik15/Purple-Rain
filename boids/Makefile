# Makefile for SDL2 project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
LIBS = -lSDL2

# Output executable
TARGET = main

# Source files
SRC = main.c boid.c

# Rules
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
