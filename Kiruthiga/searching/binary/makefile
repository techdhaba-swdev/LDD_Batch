cc = gcc
CFLAGS = -I.
DEPS = binarysearch.h
OBJ = main.c binarysearch.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
