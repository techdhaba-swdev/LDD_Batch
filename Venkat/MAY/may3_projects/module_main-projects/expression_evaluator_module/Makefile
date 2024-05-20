CC = gcc

CFLAGS = -I.

DEPS = convertToPostfix.h createStack.h evaluatePostfix.h getPrecedence.h isEmpty.h Node.h pop.h push.h 

OBJ =  convertToPostfix.o createStack.o evaluatePostfix.o getPrecedence.o isEmpty.o push.o pop.o main.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

