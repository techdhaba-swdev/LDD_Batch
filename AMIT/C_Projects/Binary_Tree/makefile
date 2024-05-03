CC=gcc
CFLAGS=-I.
DEPS=tree.h
OBJ=Binary_main.o Binary_fn.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
binary_tree:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
