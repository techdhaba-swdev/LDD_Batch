CC = gcc

CFLAGS = -I.

DEPS = node.h createGraph.h addEdge.h printGraph.h

OBJ =  node.o createGraph.o addEdge.o printGraph.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

