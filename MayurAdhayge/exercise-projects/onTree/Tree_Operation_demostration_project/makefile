$(shell gcc -c ./src/main.c  -o ./obj/main.o -I./header/)
CC=gcc
DEP_H=./header/
DEP_D=-I./include/
FLAG_M=-Wall -pg
$(shell export GMON_OUT_PREFIX=./exe/) 
LIB_SRC= $(wildcard ./include/*.c)
#LIB_SRC += ./main.c
#(shell echo $LIB_SRC)
OBJ_DIR=./obj

OBJ_LIB= $(patsubst ./include/%.c,$(OBJ_DIR)/%.o,$(LIB_SRC))

EXTRA_SRC=main.c
OBJ_EXTRA=$(OBJ_DIR)/main.o



$(shell mkdir -p $(OBJ_DIR))


#$(OBJ_DIR)/main.o: main.c
#	$(CC) -c -o $@ $< -I. -I$(DEP_H) 

$(OBJ_DIR)/%.o: ./include/%.c
	$(CC) -c -o $@ $< $(DEP_D) -I$(DEP_H)

./exe/run_project: $(OBJ_LIB) $(OBJ_EXTRA)
	$(CC) $(FLAG_M) -o $@ $^ -I. -I$(DEP_H)
	./$@
	
#mayur:
#	./exe/run_project
