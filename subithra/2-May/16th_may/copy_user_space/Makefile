
# Define kernel source directory (replace with your actual path)
KERNEL_DIR = /lib/modules/$(shell uname -r)/build

# Name of the module
MODULE_NAME = cpyuser

# C compiler flags (adjust as needed)
CC = gcc

# Object files
obj-m := $(MODULE_NAME).o

# Include kernel headers from the defined directory
$(KERNEL_DIR)/.config:
	male -C $(MODULE_NAME) M=$(PWD) headers_install

all:
	make -C $(MODULE_NAME) M=$(PWD) modules

clean:
	make -C $(MODULE_NAME) M=$(PWD) clean

# Load the module (requires root)
load:
	insmod $(MODULE_NAME).ko

# Unload the module (requires root)
unload:
	rmmod $(MODULE_NAME)


