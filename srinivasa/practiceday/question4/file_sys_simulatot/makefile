CC=gcc
FLAGS=-I.
DEPS=code.h
OBJ=main.o code.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

exe:$(OBJ)
	$(CC) -o $@ $^ $(FLAGS)
