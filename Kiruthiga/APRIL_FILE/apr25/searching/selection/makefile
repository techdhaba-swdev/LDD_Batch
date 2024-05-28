cc = gcc
CFLAGS = -I.
DEPS = selectionsort.h
OBJ = main.c selectionsort.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
