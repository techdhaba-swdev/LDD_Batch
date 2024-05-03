CC=gcc
CFLAGS=-I.
DEPS = network.h
OBJ = network.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)



