#include <stdio.h>
#include <stdlib.h>

int main()
{
	char data[] = "manual";
	FILE *fp =fopen ("details.txt" , "a");
	if(fp == NULL)
	{
		perror("erroer");
	}
	fputs(data , fp);
	fclose(fp);
	printf("data apeend success\n");
}

