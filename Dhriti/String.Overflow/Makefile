CC = gcc
CFLAGS = -I.

DEPS = main.h

OBJ = stack.o main.o


%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

my_print : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
