CC=gcc
CFLAGS=-I.
DEPS=stack.h main.h
OBJ=stack.o main.o

%.O: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
do:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
