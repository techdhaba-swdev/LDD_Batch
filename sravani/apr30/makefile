CC=gcc
CFLAGS=-I.
DEPS=bstadd.h
OBJ=bstadd.o main.o

%.o: %c $(DEPS)
	$((CC) -c -o $@ $< $(CFLAGS)
bstadd:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
