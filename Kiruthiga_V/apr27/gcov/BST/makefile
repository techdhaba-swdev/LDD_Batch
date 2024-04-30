cc = gcc
CFLAGS = -I.
DEPS = BST.h
OBJ = main.c BST.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
