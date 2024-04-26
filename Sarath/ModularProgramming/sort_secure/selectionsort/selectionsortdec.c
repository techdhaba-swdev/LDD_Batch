#include<stdio.h>
#include"selection.h"
void selectionsortdec(int a[],int length)
{       
        printf("\nDESCENDING ORDER:");
        for(int i=0;i<length-1;i++)
        {       
                int max_pos=i;
                for(int j=i+1;j<length;j++)
                {       
                        if(a[j]>a[max_pos])
			{
				max_pos=j;
			}
		}
		if(max_pos!=i)
		{
			int temp=a[i];
                        a[i]=a[max_pos];
                        a[max_pos]=temp;
                }              
        }       
} 
