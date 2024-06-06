CC = gcc

CFLAGS = -I.

DEPS = heapsor.h

OBJ =  heapsort.o main.o

%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

myprint : $(OBJ)	
	$(CC) -o $@ $^ $(CFLAGS)
