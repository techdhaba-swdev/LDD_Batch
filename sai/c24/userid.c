#include<stdio.h>

int main()
{
	int userid = 100000;
	userid++;
	if(userid>100)
	{
		puts("Grand Access");
	}
	else
	{
		puts("Deny Access");
	}
	return 0;
}

