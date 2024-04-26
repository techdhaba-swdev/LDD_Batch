#include<stdio.h>
#include"selection.h"
void selectionsortasc(int a[],int length)
{
	printf("\nASCENDING ORDER:");
	for(int i=0;i<length-1;i++)
	{
		int min_pos=i;
		for(int j=i+1;j<length;j++)
		{
			if(a[j]<a[min_pos])
			{
				min_pos=j;
			}
		}
		if(min_pos!=i)
		{
			int temp=a[i];
			a[i]=a[min_pos];
			a[min_pos]=temp;
		}
	}
}
