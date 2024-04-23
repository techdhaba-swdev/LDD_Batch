#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//entry point function 

int nomain();
int _start(){
	//calling entry point 
	nomain();
	exit(0);
}
int nomain(){
	puts("Litheefs code");
	return 0;
}
/*
int fun(){
	printf("welcome litheef\n");
	return 0;
}
void _start(){
	int x = fun();
	exit(x);
}*/
