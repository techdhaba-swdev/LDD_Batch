#include<stdio.h>

void swap(int *x,int *y);

void main()
{
int n1,n2;
printf("Enter first number:");
scanf("%d",&n1);
printf("Enter number 2:");
scanf("%d",&n2);
printf("Before swap n1=%d , n2=%d\n",n1,n2);
swap(&n1,&n2);
printf("After swap n1=%d , n2 =%d\n",n1,n2);
}
void swap(int *x,int *y)
{
int t=*x;
*x=*y;
*y=t;
}

