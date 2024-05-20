#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
#define MAX_STUDENTS 100
typedef struct {
	char name[MAX_SIZE];
	char subject[MAX_SIZE];
	char location[MAX_SIZE];
	int roll;
} Data;



void students_records(const char *Student_file, Data *students, int *count_Students) {
	FILE *file = fopen(Student_file, "r");

	if(file == NULL) {
		fprintf(stderr, "File is not opening: %s\n",file);
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	*count_Students = 0;
	Data student;

	while (fscanf (file, "%s %s %s %d", student.name, student.subject,student.location, &student.roll) == 4) {

		if (*count_Students < MAX_STUDENTS) {
			students[*count_Students] = student;

			(*count_Students)++;
		}else{
			break;
		}
	}

	fclose(file);
}

int main() {

	const char *Student_file = "student_records.txt";
	Data students[MAX_STUDENTS];
        int count_Students = 0;

	students_records(Student_file, students, &count_Students);

	for(int i=0; i<count_Students; i++) {
		printf("Name: %s\n", students[i].name);
		printf("Roll_number: %d\n", students[i].roll);
                printf("Subject: %s\n", students[i].subject);
                printf("Location: %s\n", students[i].location);
		printf("\n");
	}

	return 0;
}

