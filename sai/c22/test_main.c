#include<stdio.h>
#include<unistd.h> //For write system call

void _start()
{
	const char msg[] = "Hello world\n";
	write(1, msg, sizeof(msg) -1 );//use write sysytem call to print
        _exit(0);
}
