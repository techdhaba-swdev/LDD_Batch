CC = gcc

CFLAGS = -I.

DEPS = bst1.h

OBJ = bst1.o main_bst1.o

%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

myprint : $(OBJ)	
	$(CC) -o $@ $^ $(CFLAGS)
