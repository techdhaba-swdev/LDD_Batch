CC = gcc

CFLAGS = -I.

DEPS = insertionsort.h

OBJ =  insertionsort.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
