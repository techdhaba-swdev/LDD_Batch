CC=gcc
CFLAGS=-I.
DEPS=selection.h
OBJ=selectionsortmain.o selectionsortasc.o selectionsortdec.o
%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
makeselection:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
