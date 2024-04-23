CC = gcc
CFLAGS = -I.

DEPS = addition.h calculate.h mainfunction.h subtraction.h

OBJ = addition.o subtraction.o mainfunction.o 

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
