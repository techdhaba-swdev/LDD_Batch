CC=gcc
CFLAGS=-I.
DEPS=mystruct.h
OBJ=singlylist.o message.o insertNode.o displayList.o deleteList.o createNode.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
singly_list:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 
