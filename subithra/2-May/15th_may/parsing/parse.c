#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char id[20];
    char subject[20];
} Student;

int main() {
    FILE *file;
    char line[100];

   
    file = fopen("student_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
 printf("STUDENT DETAILS:\n");

   
    while (fgets(line, sizeof(line), file)) {
        Student student;
        if (sscanf(line, "%s %s %s", student.name, student.id, student.subject) == 3) { 
		printf(" Name: %s, ID: %s, Subject: %s\n", student.name, student.id, student.subject);
        } else {
            fprintf(stderr, "Error parsing line: %s\n", line);
        }
    }

  
    fclose(file);
    return 0;
}
