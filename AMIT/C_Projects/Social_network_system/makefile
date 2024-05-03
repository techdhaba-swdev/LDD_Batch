CC=gcc
CFLAGS=-I.
DEPS=network.h
OBJ=network_main.o network_fn.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
network_system:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
