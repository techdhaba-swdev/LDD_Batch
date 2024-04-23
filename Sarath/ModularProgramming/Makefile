CC=gcc
CFLAGS=-I.
DEPS= main.h
OBJ=main.o add.o sub.o mul.o div.o

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
module:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
