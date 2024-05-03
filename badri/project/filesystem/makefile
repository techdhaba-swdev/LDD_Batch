CC =gcc
CFLAGS = -I.
DEPS = file.h header.h 
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
file : createdir.c createfile.c content.c navigate.c delete.c search.c  main.c
	gcc -o file createdir.c createfile.c content.c navigate.c delete.c search.c  main.c -I.
