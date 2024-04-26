CC = gcc

CFLAGS = -I.

DEPS = queue.h

OBJ = queue.o main.o

%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

myprint : $(OBJ)	
	$(CC) -o $@ $^ $(CFLAGS)
