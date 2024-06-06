CC = gcc

CFLAGS = -I.

DEPS = node.h binary_tree.h

OBJ = node.o binary_tree.o main.o

%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

execute_Makefile: $(OBJ)	
	$(CC) -o $@ $^ $(CFLAGS)
