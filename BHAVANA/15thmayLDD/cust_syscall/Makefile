obj-m += sys_call.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc sys_call.c -o syscall
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f syscall
