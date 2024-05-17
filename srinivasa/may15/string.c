#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student {
	char name[100];
	int id ;
	char subject[20];
};


int main()
{
	FILE *fp;
	char line[100];
	struct Student student;
	// oping the file 
	fp = fopen("student_data.txt", "r");
	if (fp == NULL){
		printf("error opening the file\n");
		return 1;
	}
	// reading and parshing the data line by line 
	while(fgets(line, sizeof(line), fp))
	{
		sscanf(line, "%s %d %s", student.name,student.id,student.subject);
		//printing the data of the student 
		printf("name = %s\nID = %d\nsubject = %s",student.name,student.id,student.subject);
	}
	fclose(fp);
	return 0;
}

