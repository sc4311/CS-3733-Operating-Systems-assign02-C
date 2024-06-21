# Compiler
CC = gcc

# Executable name
TARGET = assign2

# Source files
SRCS = main.c array_operations.c merge_operations.c

# Object files
OBJS = $(SRCS:.c=.o)

# Flags for the compiler
CFLAGS = -Wall -Wextra -O2

# Rule for making the target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule for making the object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for cleaning the directory
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)