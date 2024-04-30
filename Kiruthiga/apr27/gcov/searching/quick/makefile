cc = gcc
CFLAGS = -I.
DEPS = quicksort.h
OBJ = main.c quicksort.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
