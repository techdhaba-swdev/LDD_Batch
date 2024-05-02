cc = gcc
CFLAGS = -I.
DEPS = graph.h
OBJ = main.c graph.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
