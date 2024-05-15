#include<stdio.h>
int main(){
	int num1, num2, avg;
	printf("enter 1st number: ");
	scanf("%d", &num1);
	printf("enter 2nd number: ");
	scanf("%d", &num2);
	avg = (num1+num2)/2;
	printf("Average: %d\n", avg);
	return 0;
}
