#include<stdio.h>
#include<unistd.h>
void nomain();
void _start(){
	nomain();
	_exit(0);
}
void nomain(){
	printf("without main");
}
