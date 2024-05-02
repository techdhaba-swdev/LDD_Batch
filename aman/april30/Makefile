CC = gcc
CFLAGS=-I.
DEPS=btree.h
OBJ=btreemain.c btree.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
btreemain: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
