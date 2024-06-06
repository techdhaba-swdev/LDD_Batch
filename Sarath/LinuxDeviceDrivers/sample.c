#include<stdio.h>
int add(int x,int y)
{
	return x+y;
}
int main()
{
	int num1,num2;
	printf("Enter value 1 to add:");
	scanf("%d",&num1);
	printf("Enter value 2 to add:");
	scanf("%d",&num2);
	printf("Addition is %d\n",add(num1,num2));
	return 0;
}
