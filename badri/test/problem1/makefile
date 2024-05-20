CC = gcc
CFLAGS = -I.
DEPS = header.h gpsstru.h
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

out : main.c parse.c updategps.c parsenmea.c
	$(CC) -o out main.c parse.c updategps.c parsenmea.c
