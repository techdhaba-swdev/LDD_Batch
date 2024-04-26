cc = gcc
CFLAGS = -I.
DEPS = doublylinkedlist.h
OBJ = main.c doublylinkedlist.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
