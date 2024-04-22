#include<stdio.h>
#include<unistd.h>
void_start()
{
	const char msg[]="HELLO, WORLD!\n";
	write(1,msg,sizeof(msg)-1);
	_exit(0);
}

