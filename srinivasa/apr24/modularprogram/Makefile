CC=gcc
GFLAGS=-I.
DEPS=stack.h function.h
OBJ=stack.o function.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(GFLAGS)

make: $(OBJ)
	$(CC) -o $@ $^ $(GFLAGS)

