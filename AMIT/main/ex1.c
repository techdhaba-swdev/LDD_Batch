#include<stdio.h>
#include<stdlib.h>
int nomain();


void _start()
{
	nomain();
	exit(0);
}
int nomain()
{
        puts("GeeksforGeeks");
        return 0;
}

