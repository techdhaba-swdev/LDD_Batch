CC = gcc

CFLAGS = -I.

DEPS = binarysearch.h

OBJ = binarysearch.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

