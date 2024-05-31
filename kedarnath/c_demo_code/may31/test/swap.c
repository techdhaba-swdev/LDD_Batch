#include<stdio.h>

int main(){

	int a=10,b=20;
	printf("before swap a is %d and b is %d\n",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("after swap a is %d and b is %d\n",a,b);
	return 0;
	
	
}
	
