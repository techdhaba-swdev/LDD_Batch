#include<stdio.h>
#include<string.h>
#define MAX_SUBJECTS 5
struct Student
{
char name [50];
int rollNumber;
float marks[MAX_SUBJECTS];
};
void createStudentRecord(struct Student *student)
{
printf("Enter student name:");
scanf("%s",student->name);
printf("enter the roll number:");
scanf("%d",&student->rollNumber);
printf("enter marks for %d subjects:", MAX_SUBJECTS);
for(int i = 0; i < MAX_SUBJECTS; ++i)
{
scanf("%f", &student->marks[i]);
}
}
void displayStudentDetails(const struct Student *student)
{
printf("student name: %s\n",student->name);
printf("Roll number: %d\n",student->rollNumber);
printf("marks for %d subjects", MAX_SUBJECTS);
for (int i =0; i< MAX_SUBJECTS; ++i)
{
printf("%.2f", student->marks[i]);
}
printf("\n");
}
int main()
{
struct Student student;
createStudentRecord(&student);
displayStudentDetails(&student);
return 0;
}
