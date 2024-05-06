# Makefile for kernal_module.c

# Specify the target object file (hello.o)
obj-m := hello.o

# Build the kernel module
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# Clean up build files
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

