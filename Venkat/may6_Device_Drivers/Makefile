# Makefile for kernal_module.c

# Specify the target object file (kernal_module.o)
obj-m := kernal_module.o

# Build the kernel module
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# Clean up build files
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
