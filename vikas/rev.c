#include<stdio.h>
#define max 5
void main()
{
	int a[max]={10,20,30,40,50};
	printf("original array: ");
	for(int i=0;i<max;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	printf("reversed array: ");
	for(int i=max-1;i>=0;i--)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
