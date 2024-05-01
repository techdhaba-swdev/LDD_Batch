#include <stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	fp = fopen("vara.txt" , "w");
	if(fp == NULL)
	{
		printf("Error : no such file! \n");
		return 1;
	}
	char data[] = "hi i am badrinath from kadapa i am doing training in linux";
		char buffer[200];
	fputs(data , fp);
	fclose(fp);

	fp = fopen("vara.txt" , "r");

	if(fp == NULL)
	{
		printf("error in opening file\n");
		return 1;
	}
	while(fgets(buffer , sizeof(buffer) , fp) !=NULL)
	{
		printf("%s",buffer);
		}
	fclose(fp);
}


