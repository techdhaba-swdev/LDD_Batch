CC=gcc
CFLAGS=-I.
DEPS=file.h

%.o: %c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

file:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
