#include<stdio.h>
#include<string.h>
struct student
{
	char name[20];
	char rollnumber[20];
	int maths_marks;
	int science_marks;
	int telugu_marks;
};
void student_record()
{
	struct student student1;
	strcpy(student1.name,"srinu");
	strcpy(student1.rollnumber,"186c11889");
	student1.maths_marks = 75;
	student1.science_marks= 80;
	student1.telugu_marks=70;
}
void display()
{
	printf("student name :%s",student1.name);
	printf("roll number:%s",student1.rollnumber);
	printf("maths marks :%d",student1.maths_marks);
	printf("science marks :%d",student1.science_marks);
	printf("telugu marks:%d",student1.telugu_marks);
}
int main ()
{
   struct student studentdetails;
   studentdetails = student_record();
   display(studentdetails);
   return 0;

}



