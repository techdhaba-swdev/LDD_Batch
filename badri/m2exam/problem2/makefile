CC = gcc 

CFLAGS = -I.

DEPS = thread.h 

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $ < $(CFLAGS)

out : pthread.c main.c
	$(CC) -o out pthread.c main.c
