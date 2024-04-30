CC = gcc

CFLAGS = -I.

DEPS =  node.h insert.h inorder.h sumofnodes.h freetree.h 

OBJ =  node.o insert.o inorder.o sumofnodes.o freetree.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

