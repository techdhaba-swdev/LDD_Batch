#include<stdio.h>
int factorial(int n){
	if(n==0 || n==1){
		printf("%d",n);
		return 1;
	}
	else{
		printf("%d*",n);
		return n*factorial(n-1);
	}
}
int main()
{
	int num=5;;
	printf("factorial of %d =",num);
	int result = factorial(num);
	printf("=%d\n",result);
	return 0;
}

