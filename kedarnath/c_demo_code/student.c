#include<stdio.h>
#include<string.h>

struct Student{
	
	char name[100];
	int rollNumber;
	float marks[5];
};



void create_Student(struct Student *student){

	printf("=====================================\n");
        printf("enter the student name\n");
        scanf("%s",student->name);
        printf("enter the student roll number\n");
        scanf("%d",&student->rollNumber);
        for(int i=0;i<5;i++){
                printf("enter the marks %d\n",i+1);
                scanf("%f",&student->marks[i]);
        }
}
void display_Student(struct Student *student){

	printf("====================================\n");
	printf("name is %s\n",student->name);
	printf("roll number is %d\n",student->rollNumber);
	for(int i=0;i<5;i++){
		printf("marks of %d is  %f\n",i+1,student->marks[i]);
	}
}

int main(){

	struct Student student;
	create_Student(&student);
	display_Student(&student);

	return 0;

}





	
