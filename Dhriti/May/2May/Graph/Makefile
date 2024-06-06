CC = gcc
CFLAGS = -I.
DEPS = graph.h
OBJ = graph.o graph_main.o

%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

graph_makefile : $(OBJ)	
	$(CC) -o $@ $^ $(CFLAGS)
