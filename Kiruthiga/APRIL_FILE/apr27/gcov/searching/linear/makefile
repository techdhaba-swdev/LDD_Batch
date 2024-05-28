cc = gcc
CFLAGS = -I.
DEPS = linearsearch.h
OBJ = main.c linearsearch.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
