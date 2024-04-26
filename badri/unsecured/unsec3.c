#include <stdio.h>
int main()
{
	char filename[10];
	FILE *file;
	char data[30];
	printf("enter the name of the file\n");
	scanf("%s",filename);
	file = fopen(filename , "w");
	if(file == NULL)
	{
		printf("error opening file!\n");
		return 1;
	}
	printf("enter data to write the file:");
	scanf("%s",data);
	fprintf(file,"%s" ,data);
	fclose(file);
	return 0;
}

