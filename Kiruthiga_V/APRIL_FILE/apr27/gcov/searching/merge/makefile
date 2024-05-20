cc = gcc
CFLAGS = -I.
DEPS = mergesort.h
OBJ = main.c mergesort.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
