CC=gcc
CFLAGS=-I.
DEPS=file.h
OBJ=file_main.o file_fn.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
File_system:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
