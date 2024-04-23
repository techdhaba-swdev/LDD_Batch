$(shell gcc -c main.c  -o ./obj/main.o -I./headers/)
CC=gcc
DEP_H=./headers/
DEP_D=-I./lib/

LIB_SRC= $(wildcard ./lib/*.c)

OBJ_DIR=./obj

OBJ_LIB= $(patsubst ./lib/%.c,$(OBJ_DIR)/%.o,$(LIB_SRC))

EXTRA_SRC=main.c
OBJ_EXTRA=$(OBJ_DIR)/main.o


$(shell mkdir -p $(OBJ_DIR))


#$(OBJ_DIR)/main.o: main.c
# 	$(CC) -c -o $@ $< -I. -I$(DEP_H) 

$(OBJ_DIR)/%.o: ./lib/%.c
	$(CC) -c -o $@ $< $(DEP_D) -I$(DEP_H)




calfile: $(OBJ_LIB) $(OBJ_EXTRA)
	$(CC) -o $@ $^ -I. -I$(DEP_H)
