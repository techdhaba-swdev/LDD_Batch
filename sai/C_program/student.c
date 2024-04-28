#include<stdio.h>

#include<string.h>

struct Student
{
	char name[100];
	int rollnumber;
	float marks[5];
};

void  studentRecorder(struct Student *student){

	printf("Enter the Student name:");
	scanf("%s\n",&student->name);

	printf("Enter the Roll Number:");
	scanf("%d\n",&student->rollnumber);

	printf("Enter the 5 subject  marks\n");
	for (int i = 0; i < 5; i++)
	{
	printf("Subject %d:",i+1);
	scanf("%f\n",&student->marks[i]);
	}

}


void displayStudentDetails(const struct Student *student)
{
   printf(" \n Student name: %s\n",student->name);
   printf("\n Student Roll number: %d\n", student->rollnumber);
   for (int i = 0; i<5 ;i++)
   {
   printf("\n Student Marks: %0.2lf\n",i+1, student->marks[i]);
   }
}

int main()
{
	struct Student student1;
	studentRecorder(&student1);

	displayStudentDetails(&student1);
}
