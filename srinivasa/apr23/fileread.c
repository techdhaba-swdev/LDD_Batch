#include<stdio.h>
int main()
{
	FILE *fp = fopen("data.txt","r");
	if (fp == NULL)
	{
		printf("error opening file\n");
		return 1 ;
	}
	char arr[200];
	char ch[200];
	fscanf(fp,"%s",ch);
	printf("%s",ch);
	while(fgets(arr,sizeof(arr),fp) !=NULL){
		printf("%s",arr);
	}
	fclose(fp);
	printf("succesfully read from the file");
	return 0;
}
