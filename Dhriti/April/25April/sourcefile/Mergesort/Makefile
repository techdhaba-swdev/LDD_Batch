CC = gcc

CFLAGS = -I.

DEPS = merge_sort.h

OBJ = merge_main.o merge_sort.o

%.o : %.c $(DEPS)	
	$(CC) -c -o $@ $< $(CFLAGS)

myprintlk : $(OBJ)	
	$(CC) -o $@ $^ $(CFLAGS)


