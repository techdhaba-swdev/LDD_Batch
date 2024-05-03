CC=gcc
CFLAGS=-I.
DEPS=file_system.h
OBJ=file_system.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
tree: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
