CC=gcc
CFLAGS=-I.
DEPS=graph1.h
OBJ=graph1.o main_graph1.c

%.o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
graph1:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
