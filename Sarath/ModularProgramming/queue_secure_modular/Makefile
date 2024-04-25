CC=gcc
CFLAGS=-I.
DEPS=queue.h
OBJ=queue.o queuemain.o
%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makequeue:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
