CC=gcc
CFLAGS=-I.
DEPS=network.h
OBJ=socialmain.o socialapi.o
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makenetwork:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
