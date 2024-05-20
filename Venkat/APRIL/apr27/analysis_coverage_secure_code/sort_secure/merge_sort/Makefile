CC = gcc

CFLAGS = -I.

DEPS = merge.h mergeSort.h printArray.h

OBJ = merge.o mergeSort.o printArray.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

