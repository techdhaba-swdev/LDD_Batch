 #include <stdio.h>

__attribute__((constructor))
	void printf_hello_world() {
		printf("hello, World!\n");
	}
