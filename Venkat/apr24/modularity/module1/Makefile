CC = gcc

CFLAGS = -I.

DEPS = string.h

OBJ =  string.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
