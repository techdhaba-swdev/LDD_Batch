CC=gcc
CFLAGS=-I.
DEPS = gps.h
OBJ = main.o gps.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
