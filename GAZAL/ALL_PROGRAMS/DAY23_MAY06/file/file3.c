#include <stdio.h>
int main(){
	int num1 = 0; int num2 = 0;
	int sum = 0;
	printf("enter first number\n");
	scanf("%d", &num1);
	 printf("enter second  number\n");
        scanf("%d", &num2);
	sum = num1 + num2;
	printf("the sum of %d + %d = %d\n", num1, num2, sum);
	return 0;
}

