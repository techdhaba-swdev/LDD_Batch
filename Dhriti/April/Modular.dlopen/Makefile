CC = gcc

CFLAGS = -I


DEPS = Modular.h

OBJ = add1.o sub1.o mul1.o div1.o Modular.o


%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

myprogram : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
