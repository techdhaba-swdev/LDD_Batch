#include<stdio.h>
#include<stdlib.h>
struct Student{

	char name[5];
	int rollNumber;
	float marks[5];
};
struct Student createStudent(){
	struct Student newStudent;
	printf("Enter student name:\n");
	scanf("%s",&newStudent.name);
	printf("Enter roll number:\n");
	scanf("%d",&newStudent.rollNumber);
	printf("Enter marks for 5 subjects:");
	for(int i=0; i<5 ; i++){
		printf("Subject %d:",i+1);
		scanf("%f",&newStudent.marks[i]);
	}
	return newStudent;
}
void displayStudent(struct Student s){
	printf("Student Details:\n");
	printf("Name:%s\n",s.name);
				printf("Roll number:%d\n",s.rollNumber);
				printf("Marks:\n");
				for(int i=0; i=5; i++){
				printf("Subject %d:%.2f\n",i+1,s.marks[i]);
				}
				}
				int main(){
				struct Student s1;
				s1 = createStudent();
				displayStudent(s1);
				return 0;
				}
