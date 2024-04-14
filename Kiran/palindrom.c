#include<stdio.h>

int  palindrom(int a)
{
	int reverse,remainder;

	while (a != 0)
	{
		remainder = a/10;
		reverse = reverse*10 + remainder;
		a /=10;
	}

	if (a == reverse)
	{
		return 0;
	}
        else 
	{
		return 1;
	}

	
}


int main()
{
	int pali;
	printf("Enter the palindrom number:");
	scanf("%d",&pali);

	if (palindrom(pali))
	{
		printf("%d is a palindrom\n",pali);
	}
	else
	{
		printf("%d is a not palindrom\n",pali);
	}
	return 0;
}

