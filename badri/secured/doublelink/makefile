CC = gcc
CFLAGS = -I.
DEPS = doublelink.h node.h
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
link : node.c doublelink.c doublemain.c
	gcc -o link node.c doublelink.c doublemain.c -I.

