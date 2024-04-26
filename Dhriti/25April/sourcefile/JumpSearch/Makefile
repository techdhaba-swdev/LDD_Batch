CC = gcc

CFLAGS = -I.

DEPS = jumpsearch.h

OBJ = jumpsearch.o jump_main.o

%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

myprint : $(OBJ)	
	$(CC) -o $@ $^ $(CFLAGS)
