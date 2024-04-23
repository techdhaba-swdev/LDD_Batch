#include <stdio.h>
struct Student {
    char name[50];
    int rollNumber;
    float marks[5]; 
};
void createStudent(struct Student *student) {
    printf("Enter name: ");
    scanf("%s", student->name);

    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);

    printf("Enter marks in 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &student->marks[i]);
    }
}
void displayStudent(struct Student student) {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Marks in 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: %.2f\n", i + 1, student.marks[i]);
    }
}
    int main() 
    {
    struct Student s; 

    printf("Enter student details:\n");
    createStudent(&s); 
    printf("\nStudent Record Created Successfully!\n");
    displayStudent(s);

    return 0;
    }
