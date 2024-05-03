cc = gcc
CFLAGS = -I.
DEPS = postfix_stack.h
OBJ = main.c postfix_stack.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
