CC=gcc
CFLAGS=-I.
DEPS=bst.h
OBJ=bstmain.o bstapi.o 
%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makebst:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
