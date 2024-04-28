#include<stdio.h>

int add(int x,int y);
int sub(int x,int y);
int main()
{
	int(*fp)(int x,int y) = add;
	printf("add is = %d\n",fp(4,6));
	fp = sub;
	printf("sub is = %d\n",fp(5,3));
}

int add(int x,int y)
{
	return x+y;
}
int sub(int x,int y)
{
	return x-y;
}
