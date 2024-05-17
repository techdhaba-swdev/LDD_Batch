CC=gcc
CFLAGS=-I.
OBJ=pthread_main.o pthread_api.o
DEPS=thread.h
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makepthread:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
