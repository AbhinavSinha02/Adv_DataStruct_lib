CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
TARGET = advanced_data_structures

SOURCES = src/avl_tree.c src/red_black_tree.c src/b_tree.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
    $(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJECTS) $(TARGET)

