#include <stdio.h>
int main()
{
	FILE *fp ;
	fp = fopen("data.txt" , "w");
	if(fp == NULL)
	{
		printf("Error : in opening file \n");
		return 1;
	}
	else
		printf("file opened successfully\n");
}
