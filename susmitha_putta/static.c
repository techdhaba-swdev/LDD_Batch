#include<stdio.h>
void function(void);
static int count =5;
main()
{
	while(count--)
	{
		func();
	}
	return ;
}
void func(void)
{
	static int i =5;
	i++;
	printf("i is %d and count is %d\n",i, count);
}
