#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 100

int main()
{
	char data[MAXLENGTH];
	FILE *fp = fopen("details.txt" , "w");
	if(fp == NULL)
	{
		perror("error");
		return -1;
	}

	printf("enter the deatails \n");

	if(fgets(data , MAXLENGTH , stdin) ==NULL)
	{
		fprintf(stderr , "error in opening file");

		return -1;
	}
	fputs(data , fp);
	fclose(fp);

	fp = fopen("details.txt" , "r");
	
	{
		if (fp == NULL)
		{
			fprintf(stderr , "error in opening file\n");
			return -1;
		}

		while(fgets(data ,MAXLENGTH , fp) != NULL)
		{

			printf("%s" , data);
			
		}
		
	}
	fclose(fp);
	return 0;
}
