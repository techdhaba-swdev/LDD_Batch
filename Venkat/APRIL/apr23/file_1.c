#include <stdio.h>
#define size 40

int main()
{
	FILE *file ;
	char content[size];

	file = fopen("data.txt" ,"r");

	if(file == NULL){
		printf("error opening file .\n");
		return 1;
	}
	fgets(content,size,file);
	fclose(file);

	printf("file content is : %s\n",content);
	return 0;
}
