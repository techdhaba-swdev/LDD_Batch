CC=gcc
CFLAGS=-I.
DEPS = treenode.h
OBJ = main.o treenode.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)



