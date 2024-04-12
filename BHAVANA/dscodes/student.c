#include <stdio.h>

#define MAX_SUBJECTS 5
#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    float marks[MAX_SUBJECTS];
};

void createStudentRecord(struct Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);

    printf("Enter marks for %d subjects:\n", MAX_SUBJECTS);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &student->marks[i]);
    }
}

void displayStudentDetails(const struct Student *student) {
    printf("\nStudent Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Marks in %d subjects:\n", MAX_SUBJECTS);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Subject %d: %.2f\n", i + 1, student->marks[i]);
    }
}

int main() {
    struct Student student;

    printf("Enter details for student:\n");
    createStudentRecord(&student);

    printf("\nDisplaying student details:\n");
    displayStudentDetails(&student);

    return 0;
}
