CC=gcc
CFLAGS=-I.
DEPS=main.h
OBJ=main.o readstrings.o writestrings.o comparestrings.o sortstrings.o
%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makestring:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
