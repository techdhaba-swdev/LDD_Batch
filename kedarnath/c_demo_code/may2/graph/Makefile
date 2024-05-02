CC=gcc
CFLAGS=-I.
DEPS = linkedlistgraph.h
OBJ = linkedlistmain.o linkedlistgraph.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

linkedlistmain: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)



