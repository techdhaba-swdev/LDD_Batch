CC = gcc

CFLAGS = -I.

DEPS = example.h main.h

OBJ =  example.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
