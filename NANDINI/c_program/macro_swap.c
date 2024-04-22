#include<stdio.h>
#define swap(x,y) (x ^= y ^= x ^= y)
int main()
{
	int num1, num2;
	printf("enter any two numbers to swap: ");
	scanf("%d%d", &num1, &num2);
	printf("values before swapping\n");
	printf("num1 = %d, num2 = %d\n\n", num1, num2);
	swap(num1, num2);
	printf("values after swapping\n");
	printf("num1 = %d, num2 = %d\n", num1, num2);
	return 0;
}

