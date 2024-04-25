#include<stdio.h>
 int add(int a, int b){
	 printf("add:%d + %d=\n",a,b);
	 return a * b;
 }
int subtract(int a, int b){
	printf("subtract:%d - %d=\n",a,b);

         return a - b;
}
int multiply(int a, int b){
	printf("multiply:%d * %d=\n",a,b);

         return a * b;
}
int divide(int a, int b){
	if(b == 0){
		return 0;

	}
	printf("divide:%d / %d=\n",a,b);

         return a / b;
}




