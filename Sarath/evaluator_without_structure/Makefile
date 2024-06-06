CC=gcc
CFLAGS=-I.
DEPS=eval.h
OBJ=evalapi.o evalmain.o
%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makeeval:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
