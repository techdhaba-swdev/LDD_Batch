#include<stdio.h>
void main()
{
	int a,b,swap;
        printf("enter a value:");
	scanf("%d",&a);
	printf("enter b value:");
	scanf("%d",&b);
	printf("before swapping values a:%d b:%d\n",a,b);
	swap=a;
	a=b;
	b=swap;
	printf("after swapping values a:%d b:%d\n",a,b);
}
