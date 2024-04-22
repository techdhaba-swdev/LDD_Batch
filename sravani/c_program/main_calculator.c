#include<stdio.h>
#include "calculator.h"
int main(){
	int a = 20;
	int b = 5;

	printf("add %d + %d = %d\n",a,b,add(a,b));
	printf("sub %d-%d = %d\n",a,b,subtract(a,b));
	printf("mul %d*%d=%d\n",a,b,multiplication(a,b));
	printf("div %d / %d = %.2f\n",a,b,division(a,b));
	return 0;
}
