CC = gcc
CFLAGS = -I.
DEPS = linearsearch.h
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
link : linearsearch.c linearmain.c
	gcc -o link linearsearch.c linearmain.c  -I.

