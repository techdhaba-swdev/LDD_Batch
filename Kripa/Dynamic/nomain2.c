#include<stdio.h>
#include<unistd.h>
void start(){
	const char msg[] = "Hello, World!\n";
	write(1, msg, sizeof(msg) -1);
	_exit(0);
}
