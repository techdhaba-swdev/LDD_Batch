CC = gcc
CFLAGS = -I.
DEPS = binarytree.h header.h newnode.h insert.h order.h sum.h
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
tree : newnode.c insert.c order.c main.c sum.c
	 gcc -o tree insert.c order.c main.c sum.c  	
	
