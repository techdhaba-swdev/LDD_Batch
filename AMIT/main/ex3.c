#include<stdio.h>
#include<unistd.h> //for write system call

void _start()
{
	const char msg[]="Hello World\n";
	write(1,msg,sizeof(msg)-1); //use wrrrite sysytem call to print
	_exit(0);                  //use _exit system call to exit
     }

