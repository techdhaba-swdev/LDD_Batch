#include<stdio.h>
void add(){
	int a,b;
	a=20;
	b=10;
	int c=a+b;
	printf("sum of %d+%d:%d\n",a,b,c);
}
void sub(){
	int a,b;
	a=45;
	b=25;
	int c=a-b;
	printf("sub of %d-%d:%d\n",a,b,c);
}
void mul(){
	int a,b;
	a=10;
	b=25;
	int c=a*b;
	printf("multiply of %d*%d:%d\n",a,b,c);
}
void div(){
	int a,b;
	a=25;
	b=5;
	float c=(float)a/b;
	printf("division of %d/%d:%.2f\n",a,b,c);
}
