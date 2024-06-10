CC = gcc
CFLAGS = -I.
DEPS = header.h

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

student : createnode.c addstu.c searchstu.c min.c delete.c bstlist.c mergelist.c splitlist.c mergesort.c printlist.c main.c
	$(CC) -o student createnode.c addstu.c searchstu.c min.c delete.c bstlist.c mergelist.c splitlist.c mergesort.c printlist.c main.c

