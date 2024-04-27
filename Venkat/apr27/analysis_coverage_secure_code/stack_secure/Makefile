CC = gcc

CFLAGS = -I.

DEPS = stack.h push.h pop.h 

OBJ =  stack.o push.o pop.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

