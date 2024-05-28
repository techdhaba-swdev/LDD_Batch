#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char name[50];
    int id;
    char subject[50];
} Student;

int main() {
    FILE *file = fopen("student.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Student student;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Parsing data from the line
        sscanf(line, "%s %d %s", student.name, &student.id, student.subject);
        
        // Printing parsed data
        printf("Name: %s\n", student.name);
        printf("ID: %d\n", student.id);
        printf("Subject: %s\n", student.subject);
        printf("\n");
    }

    fclose(file);
    return 0;
}


