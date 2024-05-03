cc = gcc
CFLAGS = -I.
DEPS =binary_tree.h
OBJ = main.c binary_tree.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
