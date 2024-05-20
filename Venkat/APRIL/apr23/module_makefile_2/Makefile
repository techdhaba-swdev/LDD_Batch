CC = gcc

CFLAGS = -I.

DEPS = add.h sub.h mul.h div.h main.h

OBJ =  add.o sub.o mul.o div.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

