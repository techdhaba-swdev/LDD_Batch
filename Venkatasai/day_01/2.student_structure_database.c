#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 5

typedef struct {
    char name[50];
    int rollNumber;
    int marks[MAX_SUBJECTS];
} Student;

// Function to create a student record
Student createStudent() {
    Student s;
    printf("Enter student name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strlen(s.name) - 1] = '\0'; // Remove the newline character
    printf("Enter roll number: ");
    scanf("%d", &s.rollNumber);
    getchar(); // Consume the newline character
    printf("Enter marks in %d subjects:\n", MAX_SUBJECTS);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Subject %d: ", i+1);
        scanf("%d", &s.marks[i]);
    }
    return s;
}

// Function to display student details
void displayStudent(Student s) {
    printf("Name: %s\n", s.name);
    printf("Roll Number: %d\n", s.rollNumber);
    printf("Marks:\n");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Subject %d: %d\n", i+1, s.marks[i]);
    }
}

int main() {
    Student student = createStudent();
    displayStudent(student);
    return 0;
}