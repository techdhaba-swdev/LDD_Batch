CC = gcc
CFLAGS = -I.
DEPS = main.h
OBJ = add.o message.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
