CC     = gcc
CFLAGS = -Wall -Wextra -I./include

# Auto-find all .c files and derive .o names
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = program

all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile — $< is the .c file, $@ is the .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
