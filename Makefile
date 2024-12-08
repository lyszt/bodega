# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Output executable
TARGET = program

# Source files
SRCS = cadastro.c compra.c free.c main.c mostrar.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c sentinela.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
