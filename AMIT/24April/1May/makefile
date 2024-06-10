CC=gcc
CFLAGS=-I.
DEPS=tree.h
OBJ=binary_tree.o binaryfn.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
binary_tree:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
