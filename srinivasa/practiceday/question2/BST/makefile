CC=gcc
FLAGS=-I.
DEPS=bst.h
OBJ=main1.o bst.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

exe:$(OBJ)
	$(CC) -o $@ $^ $(FLAGS)
