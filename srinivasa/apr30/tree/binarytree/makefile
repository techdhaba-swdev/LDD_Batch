CC=gcc
FLAGS=-I.
OBJ=main1.c binarytree.c
DEPS=binary_tree.h
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(FLAGS)
