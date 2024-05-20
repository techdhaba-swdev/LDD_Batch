cc = gcc
CFLAGS = -I.
DEPS = bubblesort.h
OBJ = main.c bubblesort.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
