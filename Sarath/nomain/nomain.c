#include<stdio.h>
#include<stdlib.h>
#define begin(m,a,i,n) m##a##i##n
#define _start begin(m,a,i,n)
int nomain();
void _start(){
	nomain();
	exit(0);
}
int nomain()
{
	puts("Emergency");
	return 0;
}
