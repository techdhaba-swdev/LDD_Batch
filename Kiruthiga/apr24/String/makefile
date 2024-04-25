cc = gcc
CFLAGS = -I.
DEPS = sort_strings.h
OBJ = main.c sort_strings.c 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
