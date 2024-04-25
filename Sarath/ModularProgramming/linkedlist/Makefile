CC=gcc 
CFLAGS=-I.
DEPS=linkedlist.h
OBJ=linkedlist.o listmain.o
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makelist:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
