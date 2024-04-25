CC=gcc
CFLAGS=-I.
DEPS = example.h 
OBJ = main.o example.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)



