#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_SIZE = 100;
const int MAX_STUDENTS = 100;

typedef struct {
    char name[MAX_SIZE];
    char subject[MAX_SIZE];
    char location[MAX_SIZE];
    int roll;
} Data;

void read_students_file(const char *const student_file, Data *const students, int *const count_students) {
    FILE *file = fopen(student_file, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s - %s\n", student_file, strerror(errno));
        exit(EXIT_FAILURE);
    }

    *count_students = 0;
    char line[MAX_SIZE * 4]; // assume each line has at most 4 fields

    while (fgets(line, sizeof(line), file)) {
        Data student;
        if (sscanf(line, "%99s %99s %99s %d", student.name, student.subject, student.location, &student.roll) == 4) {
            if (*count_students < MAX_STUDENTS) {
                students[*count_students] = student;
                (*count_students)++;
            } else {
                fprintf(stderr, "Maximum number of students reached.\n");
                break;
            }
        } else {
            fprintf(stderr, "Invalid input line: %s\n", line);
        }
    }

    fclose(file);
}

void store_students(const Data *const students, const int count_students) {
    for (int i = 0; i < count_students; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Roll number: %d\n", students[i].roll);
        printf("Subject: %s\n", students[i].subject);
        printf("Location: %s\n", students[i].location);
        printf("\n");
    }
}

int main() {
    const char *const student_file = "student_records.txt";
    Data students[MAX_STUDENTS];
    int count_students = 0;

    read_students_file(student_file, students, &count_students);
    store_students(students, count_students);

    return 0;
}
