CC=gcc
CFLAGS=-I.
DEPS=string.h
OBJ=mainstring.o stringfn.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
string_exe:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)                                
