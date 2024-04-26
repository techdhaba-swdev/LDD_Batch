CC = gcc
CFLAGS = -I.
DEPS = example.h
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

add : example.c main.c
	gcc -o add example.c main.c -I.
