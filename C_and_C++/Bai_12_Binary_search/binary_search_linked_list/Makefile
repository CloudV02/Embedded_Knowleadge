CC = gcc

CFLAGS = -I$(HEADER_DIR) -Wall -Wextra

HEADER_DIR = header
SOURCE_DIR = source

SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(SOURCES:.c =.o)

EXECUTABLE = program

all: $(EXECUTABLE) run

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^

$(SOURCE_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC)	$(CFLAGS) -c -o $@ $<

clean:
	rm	-f $(SOURCE_DIR)/*.o $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)
.PHONY: all clean run
