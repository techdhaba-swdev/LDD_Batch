obj-m+=custom_syscall.o

all:
	make -C /lib/modules/$(shelluname-r)/build M=$(pwd)modules
	gcc test_custom_syscall.c -o test_custom_syscall

clean:
	make -C /lib/modules/$(shelluname-r)/build M=$(pwd)clean
	rm -f test_custom_syscall

