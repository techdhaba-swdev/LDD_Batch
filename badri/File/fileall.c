#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char data[100];
	fp = fopen("example.txt" , "w");
	if(fp == NULL)
	{
		printf("error : not found file\n");
		exit (1);
	}
	else
	{
		printf("enter the content in file\n");
		fgets(data , sizeof(data) , stdin);
		fprintf(fp , "%s" , data);
		fclose(fp);
	}
	fp = fopen("example.txt" , "r");
	if(fp == NULL)
	{
		printf("error in opening file\n");
		exit(1);
	}
	while (fgets(data , sizeof(data) , fp) != NULL)
	{
		printf("%s",data);
	}
	fclose(fp);
	
}
