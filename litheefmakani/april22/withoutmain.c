#include<stdio.h>
#include<unistd.h>//foe write system call
void _start(){
	const char msg[]="hello litheef!\n";//it declares the constat character array with string. 
	write(1,msg,sizeof(msg)-1);//use write system call to print 
	_exit(0); //use _exit system call to exit 
}
