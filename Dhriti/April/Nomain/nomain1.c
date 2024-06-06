#include<unistd.h>
#include<stdio.h>
void _start(){

        const char msg[] = "Hello, World!\n";
	write(1,msg,sizeof(msg)-1);
        _exit(0);
}

      
