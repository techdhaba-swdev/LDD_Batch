#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct Student
{
	char name[100];
	int id;
	char subject[100];
};

int main()
{
	FILE *file;
	char filename[100];
	struct Student student;
	printf("Enter file to open:");	
	scanf("%s",filename);

	file= fopen(filename,"r");
	if(file==NULL)
	{
		perror("Error opening file");
		return 1;
	}


	while(fscanf(file, "%s%d%s",student.name,&student.id,student.subject)!= EOF)
	{

		printf("Name :%s\n",student.name);
		printf("ID:%d\n",student.id);
		printf("Subject:%s\n",student.subject);

		printf("\n");
	}
	fclose(file);

	return 0;
}


