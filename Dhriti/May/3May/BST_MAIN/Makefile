CC = gcc

CFLAGS = -I.

DEPS = bst_main.h

OBJ = bst.o bst_main.o

%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

myprint : $(OBJ)	
	$(CC) -o $@ $^ $(CFLAGS)
