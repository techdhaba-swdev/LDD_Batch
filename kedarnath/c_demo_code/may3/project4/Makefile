CC=gcc
CFLAGS=-I.
DEPS = binarytree.h
OBJ = binarytree.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)



