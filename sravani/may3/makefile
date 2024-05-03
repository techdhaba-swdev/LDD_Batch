CC=gcc
CFLAGS=-I.
DEPS=bst2.h
OBJ=bst2.o main_bst2.o

%.o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bst2:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
