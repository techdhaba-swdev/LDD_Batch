#include<stdio.h>
#include<stdlib.h>
//entry point function
extern int nomain();

int nomain(){
	puts("how are you all ");
	return 0;
}
void _start(){
        //calling entry point
        nomain();
       
}

