CC=gcc
CFLAGS=-I.
OBJ=main.h
OBJ=main1.o add.o sub.o mul.o div.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
