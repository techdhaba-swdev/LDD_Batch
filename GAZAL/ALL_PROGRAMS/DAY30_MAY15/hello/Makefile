obj-m += hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) 
	modules
        gcc hello.c -o test_hello
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	
	rm -f test_hello
	
