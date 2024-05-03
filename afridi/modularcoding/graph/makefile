CC = gcc.
CFLAGS = -I.
DEPS = node.h graph.h
%.o: %.c $(DEPS) $(CC) -c -o $0 $< $(CFLAGS)
graph: graph.c node.c main.c
	gcc -o graph graph.c node.c main.c
