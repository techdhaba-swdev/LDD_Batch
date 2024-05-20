CC = gcc

CFLAGS = -I.

DEPS = pthread.h

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $ < $(CFLAGS)

out : pthread.c main.c
	$(CC) -o out pthread.c main.c
