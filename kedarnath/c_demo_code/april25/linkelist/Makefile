CC=gcc
CFLAGS=-I.
DEPS = list.h
OBJ = main.o list.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

