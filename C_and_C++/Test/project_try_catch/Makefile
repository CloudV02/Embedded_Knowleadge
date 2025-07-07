

PRO_DIR = .



OBJ_FILES = $(subst .c,.o,$(notdir $(wildcard $(PRO_DIR)/try_catch/*.c)))
INC_DIR = $(PRO_DIR)/try_catch

vpath %.c .

all: program2

program1: goto.o
	gcc $< -o $@.exe
	./$@.exe

program2: setjump.o
	gcc $< -o $@.exe
	./$@.exe

program3: $(OBJ_FILES) $(INC_DIR)
	gcc $(OBJ_FILES) -o ./try_catch/$@.exe
	./try_catch/$@.exe

%.o: %.c
	gcc -c $< -o $@

print-%:
	echo $($(subst print-,,$@))