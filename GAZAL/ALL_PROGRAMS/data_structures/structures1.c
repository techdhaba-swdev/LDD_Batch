#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    int marks[3];
};


struct Student createStudentRecord() {
    struct Student student;

    printf("Enter name of student: ");
    scanf("%s", student.name);

    printf("Enter roll number: ");
    scanf("%d", &student.rollNumber);

    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &student.marks[i]);
    }

    return student;
}

void displayStudentDetails(struct Student student) {
    printf("\nStudent details:\n");
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Marks in 3 subjects:\n");
    for (int i = 0; i < 3; ++i) {
        printf("Subject %d: %d\n", i + 1, student.marks[i]);
    }
}

int main() {
    struct Student student;
    student = createStudentRecord();
    displayStudentDetails(student);
    
    return 0;
}