cc = gcc
CFLAGS = -I.
DEPS = cal.h
OBJ = main.c cal.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
