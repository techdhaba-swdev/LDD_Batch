#include<stdio.h>
int main()
{
	FILE *fp = fopen("data.txt", "w");
	if(fp == NULL)
	{
		printf("Error opening file!\n");
		return 1;
	}
	char arr[200];
	char ch[100];
	
	fscanf(fp, "%s",ch);
	printf("%s\n",ch);

	while(fgets(arr, sizeof(arr), fp)!= NULL)
	{
		printf("%s", arr);
	}

	fclose(fp);
	
	printf("Successfully read to the file.\n");
	printf("hello!File handling functions.\n");
	return 0;
}

