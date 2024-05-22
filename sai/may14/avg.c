#include<stdio.h>

int main(){
	int num1,num2;

	printf("Enter the first integer:");
	scanf("%d",&num1);
	printf("\nEnter the second integer: ");

	scanf("%d\n",&num2);

	printf("\nAvg = %f\n",(float)(num1+num2)/2);

	return 0;
}
