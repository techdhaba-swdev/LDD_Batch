#include<stdio.h>
int add (int a, int b)
{
	return (a+b);
}

int sub (int a,int b)
{
	return (a-b);
}

int mul(int a, int b)
{
	return (a*b);
}
int div(int a, int b)
{
	return (a/b);
}
int cal_dynamic(int a, int b)
{



       	printf("add = %d\n",add(a,b));
        printf("sub = %d\n",sub(a,b));
        printf("mul = %d\n",mul(a,b));
        printf("div = %d\n",div(a,b));

	return 0;

}	


