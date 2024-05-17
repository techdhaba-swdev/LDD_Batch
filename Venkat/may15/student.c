#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_SUBJECT_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    int id;
    char subject[MAX_SUBJECT_LEN];
} Student;

void parseStudentRecord(char *line, Student student) {
    char *token = strtok(line, ",");
    if (token != NULL) {
        strncpy(student.name, token, MAX_NAME_LEN - 1);
        student.name[MAX_NAME_LEN - 1] = '\0';
    }

    token = strtok(NULL, ",");
    if (token != NULL) {
        student.id = atoi(token);
    }

    token = strtok(NULL, ",");
    if (token != NULL) {
        strncpy(student.subject, token, MAX_SUBJECT_LEN - 1);
        student.subject[MAX_SUBJECT_LEN - 1] = '\0';
    }
}

int main() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        Student student;
        parseStudentRecord(line, student);
        printf("Name: %s\nID: %d\nSubject: %s\n\n", student.name, student.id, student.subject);
    }

    fclose(file);
    return 0;
}
