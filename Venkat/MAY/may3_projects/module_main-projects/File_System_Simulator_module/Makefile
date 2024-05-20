CC = gcc

CFLAGS = -I.

DEPS = Node.h CreateNode.h AddChildNode.h ListDirectoryContents.h NavigateToSubdirectory.h SearchFile.h DeleteNode.h

OBJ = CreateNode.o AddChildNode.o ListDirectoryContents.o NavigateToSubdirectory.o SearchFile.o DeleteNode.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

