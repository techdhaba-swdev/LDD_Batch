#include<stdio.h>

int main()
{
	FILE *fp=fopen("data.txt","r"); //open file data.txt for read
	
	if(fp==NULL)
	{
		printf("Error opening file!\n");
		return 1;
	}

	char arr[100];

	//fscanf(fp,0,SEEK_SET);

	while(fgets(arr,sizeof(arr),fp)!=NULL)
	{
		printf("%s",arr);
	}

	//close file
	fclose(fp);
	printf("successfully read from the file.\n");
	return 0;
}

