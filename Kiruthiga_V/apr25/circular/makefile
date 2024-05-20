cc = gcc
CFLAGS = -I.
DEPS = circularlinkedlist.h
OBJ = main.c circularlinkedlist.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
