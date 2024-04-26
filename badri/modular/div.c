#include<stdio.h>
int divs1(int x , int y)
{ 
	if(y==0)
	{
		printf("no zero value");
	}
	else
	return x/y;
}
int divs2(int x , int y , int z)
{ 
	if(y==0 & z==0)
	{
		printf("no zero value");
	}
	else
	return ((x/y)/z);
}
int divs3(int x , int y , int z ,int a)
{ 
	if(y==0 & z==0)
	{
		printf("no zero value");
	}
	else
	return (((x/y)/z)/a);
}
