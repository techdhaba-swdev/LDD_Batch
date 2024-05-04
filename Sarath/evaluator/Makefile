CC=gcc
CFLAGS=-I.
DEPS=eval.h
OBJ=evalmain.o evalapi.o
%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makeeval:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
