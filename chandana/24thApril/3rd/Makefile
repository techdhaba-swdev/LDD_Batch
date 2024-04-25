CFLAGS=-I.
DEPS=string_util.h
OBJ=string_util.o main.o

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
string: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
