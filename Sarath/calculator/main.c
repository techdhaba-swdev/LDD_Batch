#include<stdio.h>

int add(int x,int y);
int mul(int x,int y);
int sub(int x,int y);
int div(int x,int y);
int main()
{
	 printf("addition is %d\n",add(3,4));
	 printf("multiplication is %d\n",mul(5,6));
	 printf("SUbtraction is %d\n",sub(7,2));
	 printf("Division is %d\n",div(6,3));
	 return 0;
}

