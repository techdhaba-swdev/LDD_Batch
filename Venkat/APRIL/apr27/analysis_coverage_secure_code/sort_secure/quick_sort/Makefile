CC = gcc

CFLAGS = -I.

DEPS = partition.h printArray.h quickSort.h swap.h

OBJ =  partition.o printArray.o quickSort.o swap.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

