CC = gcc
CFLAGS = -I.
DEPS = expression.h stack.h
%.O : %.C $(DEPS)
	$(CC) -C -O $@ $< $(CFLAGS)
expression : expression.c main.c stack.c
	gcc -o expression expression.c main.c stack.c
