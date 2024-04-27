CC=gcc
CFLAGS=-I.
OBJ=print_message.h
OBJ=main.o add.o message.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

