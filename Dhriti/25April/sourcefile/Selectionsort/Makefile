CC = gcc

CFLAGS = -I.

DEPS = print_array.h selection_sort.h swap.h

OBJ = selection_sort.o mainS.o swap.o print_array.o

%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

myprintlk : $(OBJ)	
	$(CC) -o $@ $^ $(CFLAGS)


