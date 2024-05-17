C=gcc
CFLAGS=-I.
DEPS=file.h
OBJ=file.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
file: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
