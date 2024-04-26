CC=gcc
CFLAGS=-I.
DEPS=bubblesort.h
OBJ=bubblesortmain.o bubblesortapi.o bubblesortapidec.o
%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makebubble:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
