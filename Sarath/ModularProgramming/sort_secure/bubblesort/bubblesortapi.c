#include<stdio.h>
void bubblesort(int a[],int length)
{
	printf("\nASCENDING ORDER: ");
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
