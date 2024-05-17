#include<stdio.h>

#define NOOF_STUDENTS 50

struct student
{
	char name[30];
	int id;
	char subject[30];
	float marks;
	char grade[2];
};

int main()
{
	struct student stu[NOOF_STUDENTS];
	int num_students = 0;

	FILE *file = fopen("student_data.txt" ,"r");
	if (file ==NULL)
	{
	printf("error opening file.\n");
	return 1;
	}
	
	while(fscanf(file , "%s %d %s %f %s" , stu[num_students].name , &stu[num_students].id , stu[num_students].subject , &stu[num_students].marks , stu[num_students].grade) != EOF)
	{
	num_students++;
	if(num_students >= NOOF_STUDENTS)
	{
	printf("maximum number of students reached\n");
		break;
	}
}

	fclose(file);
	
	printf("student data : \n");
	for(int i =0 ; i< num_students ; i++)
	{
	printf("name ; %s , id : %d , subject : %s , marks : %f , grade : %s \n",stu[i].name , stu[i].id , stu[i].subject  , stu[i].marks , stu[i].grade);

	}
	return 0;
	}

