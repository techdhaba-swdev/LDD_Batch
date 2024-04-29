#include<stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("data.txt" , "r");
	if(fp == NULL)
	{
		printf("error in opeing in file \n");
	}
	else
	printf("successfully opened file in read mode\n");
}

