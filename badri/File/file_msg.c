#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp ;
	fp = fopen("badri.txt" ,"w");
	if(fp == NULL)
	{
		printf("error: no such file\n");
	}
	char buffer[100];
	char content[] = "hi my name is memory123 zigabyte robo lilli";
	fputs(content , fp);
	fclose(fp);

	fp = fopen("badri.txt" , "r");
	if(fp == NULL)
	{
		printf("error : in opening file\n");
	}
	while(fgets(buffer , sizeof(buffer) , fp) !=NULL)
	{
		printf("%s",content);
	}
}


