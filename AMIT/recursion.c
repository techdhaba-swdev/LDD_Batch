#include<stdio.h>

void printNum(int n)
{
	if(n<=10)
	{
		printf("Number is=%d\n",n);
		printNum(n+1);
	}

}
  int main()
{
	printf("values are");
	printNum(1);
	return 0;
}
