CFLAGS=-I.
DEPS=gps.h
OBJ=gps.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
gps: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
