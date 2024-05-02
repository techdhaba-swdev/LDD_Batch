CC=gcc
CFLAGS=-I.
DEPS=graph.h
OBJ=graph_array.o graph_array_api.o
%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makegraph:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
