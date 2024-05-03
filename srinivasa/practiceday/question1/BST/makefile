CC=gcc
FLAGS=-I.
DEPS=bst.h
OBJ=main.o bst.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

make: $(OBJ)
	$(CC) -o $@ $^ $(FLAGS)
