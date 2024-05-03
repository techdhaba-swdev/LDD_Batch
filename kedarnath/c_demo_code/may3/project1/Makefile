CC=gcc
CFLAGS=-I.
DEPS = tree.h
OBJ = tree.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)



