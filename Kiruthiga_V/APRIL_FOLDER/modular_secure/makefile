cc = gcc
CFLAGS = -I.
DEPS = linkedlist.h
OBJ = main.c linkedlist.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
