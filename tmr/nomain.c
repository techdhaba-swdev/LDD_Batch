#include<stdio.h>
#include<unistd.h>  
void_start()
{
	const char msg[]="hello,world!\n";
	write(1,msg,sizeof(msg) -1); 
	_exit(0); 
}

