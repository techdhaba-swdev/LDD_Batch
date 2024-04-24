CC = gcc
CFLAGS = -I.
DEPS = add1.h sub1.h mul1.h div1.h
OBJ = main1.o add1.o sub1.o mul1.o div1.o
%o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
