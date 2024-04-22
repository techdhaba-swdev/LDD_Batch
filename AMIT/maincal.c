#include<stdio.h>
int add(int a,int b);
int divide(int c,int d);
int sub(int e, int f);
int mul(int g,int h);

int main()
{
	int x=8;
	int y=2;

	printf("Add=%d",add(x,y));
	printf("divide=%d\n",divide(x,y));
	printf("sub=%d\n",sub(x,y));
	printf("multiply=%d\n",mul(x,y));
}
