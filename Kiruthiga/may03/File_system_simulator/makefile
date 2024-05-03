cc = gcc
CFLAGS = -I.
DEPS = file_system.h
OBJ = main.c file_system.c
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
