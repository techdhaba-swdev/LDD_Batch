CC=gcc
CFLAGS=-I.
DEPS=binarysearch.h
OBJ=binarymain.o binaryapi.o
%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makebinary:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
