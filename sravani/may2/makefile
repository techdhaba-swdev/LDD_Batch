CC=gcc
CFLAGS=-I.
DEPS=graph.h
OBJ=gaph_mat.o main_mat.o

%.o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
graph:$(OBJ)
	$(CC) -o $@ $^ $(CFALGS)
