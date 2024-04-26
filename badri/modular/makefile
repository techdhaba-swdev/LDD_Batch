CC=gcc
CFLAGS = -I.
DEPS = cal.h
%.o: %.c $ (DEPS)
	$(cc) -c -o $@ $< $(CFLAGS)
cal : sum.c sub.c mul.c div.c main.c
	$(CC) -o cal sum.c sub.c mul.c div.c main.c 
