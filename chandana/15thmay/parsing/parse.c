#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define MAX_SUBJECT_LEN 50

void student_records(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "chandu,1,Math\n");
    fprintf(file, "ram,2,Science\n");
    fprintf(file, "radha,3,History\n");
    fclose(file);
}

void parse(const char *filename, char names[MAX_STUDENTS][MAX_NAME_LEN], int ids[MAX_STUDENTS], char subjects[MAX_STUDENTS][MAX_SUBJECT_LEN], size_t *num_students) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[256];
    size_t count = 0;
    while (fgets(buffer, sizeof(buffer), file) && count < MAX_STUDENTS) {
        char *name = strtok(buffer, ",");
        char *id_str = strtok(NULL, ",");
        char *subject = strtok(NULL, "\n");

        if (name && id_str && subject) {
            strncpy(names[count], name, MAX_NAME_LEN - 1);
            names[count][MAX_NAME_LEN - 1] = '\0'; // Ensure null-terminated string
            ids[count] = atoi(id_str);
            strncpy(subjects[count], subject, MAX_SUBJECT_LEN - 1);
            subjects[count][MAX_SUBJECT_LEN - 1] = '\0'; // Ensure null-terminated string
            count++;
        } else {
            fprintf(stderr, "Error parsing line: %s\n", buffer);
        }
    }
    *num_students = count;

    fclose(file);
}

int main() {
    const char *filename = "student_records.txt";
    student_records(filename);

    char names[MAX_STUDENTS][MAX_NAME_LEN];
    int ids[MAX_STUDENTS];
    char subjects[MAX_STUDENTS][MAX_SUBJECT_LEN];
    size_t num_students = 0;

    parse(filename, names, ids, subjects, &num_students);

    for (size_t i = 0; i < num_students; ++i) {
        printf("Student %zu:\n", i + 1);
        printf("  Name: %s\n", names[i]);
        printf("  ID: %d\n", ids[i]);
        printf("  Subject: %s\n", subjects[i]);
    }

    return 0;
}
