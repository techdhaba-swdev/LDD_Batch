CC = gcc

CFLAGS = -I.

DEPS = node.h insert.h search.h inordertraversal.h 

OBJ = node.o insert.o search.o inordertraversal.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
