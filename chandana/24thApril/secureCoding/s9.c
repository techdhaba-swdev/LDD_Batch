//Integer Overflow

#include <stdio.h>

int main() {
	int a=2147483647; //Maximum value of int 
	int b=10;
	int result = a+b;//Integer overflow
	printf("result:%d\n",result);
	return 0;
}
