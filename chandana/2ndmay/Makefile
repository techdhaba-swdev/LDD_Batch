CC=gcc
CFLAGS=-I.
DEPS=binary_tree.h
OBJ=binary_tree.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
tree: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

