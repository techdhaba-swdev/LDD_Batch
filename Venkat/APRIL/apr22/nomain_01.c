#include <stdio.h>
#include <unistd.h>   // for write system call

void _start() {
	const char msg[] = "hello, world!\n";
	write(1, msg,sizeof(msg) -1);  // use write system call to print 
	_exit(0);   // use _exit system call to exit 
		 }

