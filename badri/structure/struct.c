#include <stdio.h>
#include <string.h>
#pragma pack(1)
int main()
{
	union student 
	{
		int roll;
		char name[30];
		float marks;
	};

	union student student1;
	student1.roll = 1034;
	
	
	printf("student roll number:%d\n",student1.roll);
	strcpy(student1.name , "badrinath");
	printf("student name : %s\n",student1.name);
	student1.marks = 95.5;
	printf("student marks : %f\n",student1.marks);
	printf("size of student1 :%d\n",sizeof(student1));
}

	
