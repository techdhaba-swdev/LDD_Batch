CC=gcc
FLAGS=-I.
DEPS=func.h
OBJ=main.o func.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

make: $(OBJ)
	$(CC) -o $@ $^ $(FLAGS)
