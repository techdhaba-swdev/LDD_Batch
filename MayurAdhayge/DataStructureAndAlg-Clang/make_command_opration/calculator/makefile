cc=gcc
dep_H=./header/dependencies.h
dep_D=-I./dependencies/

# List all source files
src=$(wildcard dependencies/*.c)

# Generate object file names from source file names
obj=$(src:.c=.o)

# Rule to compile .c files into .o files
%.o : %.c
	$(cc) -c -o $@ $< $(dep_D) 

# Rule to link object files into the final executable
calfile: $(obj)
	$(cc) -o $@ $^ -I. -I$(dep_H)
