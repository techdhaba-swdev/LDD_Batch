#include<stdio.h>
int main()
{
	FILE *fp =fopen("data.txt","w");
	if(fp==NULL)
	{
		printf("error opening");
		return 1;
	}
	fprintf(fp,"this is sample text written to file.\n");
	fclose(fp);
	printf("succesfully wrote in the file./n");
	return 0;
}
         
	
