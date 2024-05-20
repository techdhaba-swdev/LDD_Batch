CC = gcc

CFLAGS = -I.

DEPS = bubbleSort.h

OBJ =  bubbleSort.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

