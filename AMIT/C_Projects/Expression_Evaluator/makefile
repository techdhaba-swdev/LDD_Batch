CC=gcc
CFLAGS=-I.
DEPS=infix.h
OBJ=evaluator_main.o evaluator_fn.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
infix_evaluator:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
