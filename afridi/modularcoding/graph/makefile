CC = gcc.
CFLAGS = -I.
DEPS = graph.h
%.o: %.c $(DEPS) $(CC) -c -o $0 $< $(CFLAGS)
graph: graph.c graphmain.c
	gcc -o graph graph.c graphmain.c
