#include<stdio.h>

int add(int x,int y);
int sub(int x,int y);
int main()
{
	int (*fp)(int,int)=add;
	printf("Add:%d\n",fp(7,4));
	fp=sub;
	printf("Sub:%d\n",fp(7,4));

	return 0;
}
int add(int x,int y)
{
	return x+y;
}
int sub(int x,int y)
{
	return x-y;
}

