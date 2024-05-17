#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    char subject[50];
} Student;

void parseLine(char *line, Student *s) {
    char *token = strtok(line, ",");
    strcpy(s->name, token);

    token = strtok(NULL, ",");
    s->id = atoi(token);

    token = strtok(NULL, ",");
    strcpy(s->subject, token);
}

int main() {
    FILE *csvFile = fopen("students.csv", "r");
    FILE *txtFile = fopen("file.txt", "w");
    char line[150];
    Student student;


    while (fgets(line, sizeof(line), csvFile)) {
        parseLine(line, &student);
        fprintf(txtFile, "Name: %s ID: %d Subject: %s\n", student.name, student.id, student.subject);
    }

    fclose(csvFile);
    fclose(txtFile);


    txtFile = fopen("file.txt","r");
    printf("content of file\n");
    while (fgets(line,sizeof(line),txtFile)) {
	    printf("%s",line);
    }
    fclose(txtFile);

    return 0;
}
