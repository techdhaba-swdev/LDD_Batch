CC=gcc
CFLAGS=-I.
OBJ=main.o thread.o 
DEPS=thread.h
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


