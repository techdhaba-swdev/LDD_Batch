cc = gcc
CFLAGS = -I.
DEPS = heapsort.h
OBJ = main.c heapsort.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
