CC = gcc

CFLAGS = -I.

DEPS = comparestrings.h readstrings.h sortstrings.h writestrings.h

OBJ =  comparestrings.o readstrings.o sortstrings.o writestrings.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
