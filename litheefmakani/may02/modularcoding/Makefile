CC = gcc

CFLAGS = -I.

DEPS = graph.h addedge.h intializegraph.h printgraph.h

OBJ = addedge.o intializegraph.o main.o printgraph.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
exe: $(OBJ)
	$(cc) -o $@ $^ $(CFLAGS)
