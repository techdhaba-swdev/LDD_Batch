#include<stdio.h>
int add(int x, int y);
int sub(int x, int y);
int main()
{
	int (*fp1)(int,int) = add;
	printf("add id %d \n", fp1(4,3));
	int (*f2)(int,int) = sub;
	printf("sub is %d\n", fp2(4,3));
	return 0;
}
int add(int x, int y)
{
	return x+y;
}
int sub(intx, inty)
{
	return x-y;

}


