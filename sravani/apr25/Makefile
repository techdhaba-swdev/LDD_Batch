CC=gcc
CFLAGS=-I.
DEPS=linklist.h
OBJ=linklist.o llmain.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

linklist:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
