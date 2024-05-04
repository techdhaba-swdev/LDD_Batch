CC = gcc

CFLAGS = -I.

DEPS = stack.h expression.h

OBJ = stack.o expression.o main.o

%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

myprogram : $(OBJ)	
	$(CC) -o $@ $^ $(CFLAGS)
