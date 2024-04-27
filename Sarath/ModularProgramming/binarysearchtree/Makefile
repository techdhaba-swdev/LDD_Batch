CC=gcc
CFLAGS=-I.
DEPS=binarysearchtree.h
OBJ=binarysearchtreemain.o binarysearchtreeapi.o
%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makebinarysearchtree:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
