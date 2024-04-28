#include<stdio.h>
#include"calculator.h"

int main()
{
	int a = 6;
	int b = 10;
	printf("Add %d + %d = %d\n",a,b,addition(a,b));
	printf("sub %d - %d = %d\n",a,b,subtraction(a,b));
        printf("mul %d * %d = %d\n",a,b,multiplication(a,b));
        printf("div %d / %d = %d\n",a,b,division(a,b));
	return 0;
}

