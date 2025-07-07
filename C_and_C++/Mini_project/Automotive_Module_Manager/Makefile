CC = gcc

PRO_DIR = .
SRC_FILES = $(notdir $(wildcard $(PRO_DIR)/*.c))
OBJ_FILES = $(SRC_FILES:.c=.o)

INC_DIR = $(PRO_DIR)

vpath %.c $(PRO_DIR)

all: program

program: $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o program.exe
	./program.exe

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: all program clean

clean:
	rm -f *.o program.exe
