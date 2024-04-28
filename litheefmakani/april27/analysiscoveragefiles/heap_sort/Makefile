CC = gcc

CFLAGS = -I.

DEPS = heapify.h heapSort.h printArray.h swap.h

OBJ =  heapify.o heapSort.o printArray.o swap.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

