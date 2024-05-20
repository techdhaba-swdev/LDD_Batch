CC = gcc 

CFLAGS = -I.

DEPS = add.h cal.h main.h sub.h 

OBJ =  add.o sub.o main.o sub.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

