CC=gcc
CFLAGS=-I.
DEPS=stack.h
OBJ=stack.o init.o push.o pop.o empty.o full.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stack_exe:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
