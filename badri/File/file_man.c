#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
char buffer [ MAX_LEN];
char data[] = {"hi i am badri id : 0161034 name :badrinath"};
int main()
{
	FILE *fp = fopen("mom.txt" , "w");
	if(fp == NULL)
	{
		fprintf(stderr , "error in oepning file \n" , fp);
		return -1;

	}
	fputs(data , fp);
	fclose(fp);

	fp=fopen("mom.txt" , "r");
	if(fp == NULL)
	{
		fprintf(stderr , "error in opening  \n " , fp);
		return -1;
	}
	while(fgets(buffer , MAX_LEN , fp) != NULL )
	{
		printf("%s" , buffer);
	}



	fclose(fp);
	return 0;
	}


