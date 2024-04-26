CC = gcc
CFLAGS = -I.
DEPS = quicksort.h 
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
link : quicksort.c  quickmain.c
	gcc -o link quicksort.c  quickmain.c -I.

