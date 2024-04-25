CC=gcc
CFLAGS=-I.
DEPS=main.h stack.h
OBJ=stack.o main.o

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
stack: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
