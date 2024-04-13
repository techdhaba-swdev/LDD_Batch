#include <stdio.h>

// Define the structure for Student
struct Student {
    char name[50];
    int rollNumber;
    float marks[5]; // Assuming 5 subjects
};

// Function to create a student record
void createStudent(struct Student *student) {
    printf("Enter name: ");
    scanf("%s", student->name);
    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);
    printf("Enter marks for 5 subjects: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &student->marks[i]);
    }
}

// Function to display student details
void displayStudent(struct Student student) {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Marks:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: %.2f\n", i + 1, student.marks[i]);
    }
}

// Main function to demonstrate usage
int main() {
    struct Student student;

    // Create student record
    createStudent(&student);

    // Display student details
    displayStudent(student);

    return 0;
}
