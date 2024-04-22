#include<stdio.h>
#include<unistd.h>
void _start(){
	const char msg[]="Hello peopleeeee\n";
	write(1,msg,sizeof(msg)-5);
	_exit(0);
}
