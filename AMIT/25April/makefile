CC=gcc
CFLAGS=-I.
DEPS=example.h
OBJ=example.o print.o add.o sub.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
example:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)  
