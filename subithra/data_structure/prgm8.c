#include<stdio.h>
struct Student{
	char name[50];
	int rollnum;
	float marks[5];
};
int main()
{
	struct Student student;
	printf("enter name");
	scanf("%s",student.name);

	printf("enter roll number");
        scanf("%d",&student.rollnum);

	printf("enter marks for 5 subject");
	for(int i=0;i<5;i++)
	{
		printf("subject %d",i+1);
	
        scanf("%f",&student.marks[i]);
	}
	printf("student details:\n");
	 printf("student name: %s\n",student.name);
	 printf("roll number:%d\n",student.rollnum);
	 printf("subject marks:\n");
	 for(int i=0;i<5;i++)
	 {
		 printf("subject %d:%.2f\n",i+1,student.marks[i]);
	 }
	 return 0;
}
