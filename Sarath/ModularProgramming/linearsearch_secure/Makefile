CC=gcc
CFLAGS=-I.
DEPS=linear.h
OBJ=linearsearch_main.o linear.o
%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makelinear:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
