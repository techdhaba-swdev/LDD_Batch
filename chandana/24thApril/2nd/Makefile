CC=gcc
CFLAGS=-I.
DEPS=sort.h 
OBJ=sort.o main.o

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
sort: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
