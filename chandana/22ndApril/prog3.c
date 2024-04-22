#include <stdio.h>
#include <unistd.h>

void _start() {
	const char msg[] = "Hello Wolrd!\n";
	write(1,msg,sizeof(msg) -1);//use write system to call print
	_exit(0);//use _exit system call to exit`
}
