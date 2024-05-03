CC=gcc
CFLAGS=-I.
DEPS=expression_evaluator.h stack.h
OBJ=stack.o Expression_evaluator.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
stack: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
