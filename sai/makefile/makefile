CC=gcc
CFLAGS=-I.
DEPS = add.h
OBJ = add.o mainadd.o 

%.o: %.c $(DEPS)
 	$(CC) -c -o $@ $< $(CFLAGS)

add: $(OBJ)
  	$(CC) -o $@ $^ $(CFLAGS)
