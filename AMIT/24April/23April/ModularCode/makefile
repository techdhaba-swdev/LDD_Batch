CC=gcc
CFLAGS=-I.
DEPS=main.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

modular:main.o add.o sub.o mul.o div.o
	$(CC) -o modular main.o add.o sub.o mul.o div.o
