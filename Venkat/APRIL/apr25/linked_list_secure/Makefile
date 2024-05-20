CC = gcc

CFLAGS = -I.

DEPS = main.h linklist.h

OBJ =  main.o linklist.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
