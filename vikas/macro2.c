#include<stdio.h>
#define swap(a,b) { int t=a; a=b; b=t; }
void main()
{
	int a=5;
	int b=10;
	printf("before swapping a:%d and b:%d\n",a,b);
	swap(a,b);
	printf("after swapping a:%d and b:%d\n",a,b);
}
