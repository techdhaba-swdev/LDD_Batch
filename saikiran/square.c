#include<stdio.h>
#define square(x) ((x * x))
int main()
{
	int num1 = 5;
	int num2 = 10;
	printf("square of %d is %d\n",num1,square(num1));
	printf("square of %d is %d\n", num2, square(num2));
	return 0;
}

