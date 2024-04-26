#include<stdio.h>
int main(){

	FILE *fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		printf("there is nothing in file to read\n");
		return 1;
	}
	char str[100];
	fgets(str,sizeof(str),fp);
	printf("%s\n",str);
	fclose(fp);
	printf("successfully read the file\n");
}
