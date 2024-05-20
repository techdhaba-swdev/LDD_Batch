cc = gcc
CFLAGS = -I.
DEPS = stack.h
OBJ = main.c stack.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
