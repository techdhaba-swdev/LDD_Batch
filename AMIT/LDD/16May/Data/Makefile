# Define kernel source directory (replace with your actual path)
KERNEL_DIR = /lib/modules/$(shell uname -r)/build

# Name of the module
MODULE_NAME = data_transfer2

# Object files
obj-m := $(MODULE_NAME).o


all:
	make -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean
