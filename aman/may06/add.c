#include<stdio.h>
int main(){
	int num1, num2, sum;
	printf("enter 1st  number: ");
	scanf("%d", &num1);
	printf("enter 2nd number: ");
	scanf("%d", &num2);
	sum = num1 + num2;
	printf("sum of two numbers %d and %d is: %d\n", num1, num2, sum);
	return 0;
}
