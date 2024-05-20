cc = gcc
CFLAGS = -I.
DEPS = insertionsort.h
OBJ = main.c insertionsort.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
