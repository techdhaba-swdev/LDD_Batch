#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	fp = fopen("gani.txt" , "w");
	if (fp == NULL)
		{
			printf("error no such file\n");
			return 1;
		}
	char content[100];
	printf("enter the text \n");
	scanf("%s" , content);
	fprintf(fp , "%s" , content);
	fclose(fp);
	
	 
        fp = fopen("gani.txt" , "r");
        if (fp == NULL)
                {
                        printf("error no such file\n");
                        return 1;
                }
	while(fgets(content , sizeof(content) , fp) != NULL)
	{
		printf("%s" , content);
	}
	fclose(fp);
}



