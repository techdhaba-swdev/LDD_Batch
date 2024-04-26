cc=gcc
CFLAGS = -I
DEPS = file_io.h 
%.o: %.c $ (DEPS)
	$(CC) -c-o $@ $< $(CFLAGS)
file_io : stringop.c sorting.c file_io.c mainstr.c 
	$(CC) -o stringop.c sorting.c file_io.c mainstr.c
