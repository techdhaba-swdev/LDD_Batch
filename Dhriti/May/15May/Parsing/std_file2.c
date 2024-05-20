#include <stdio.h>

// Structure to hold student information
struct Student {
    char name[50];
    int id;
    char subject[50];
};

void student_data(const char *filename) {
    FILE *file;
    struct Student students[] = {
        {"dileep",1, "Math"},
        {"charan",2, "Physics"},
        {"kevin",3, "Chemistry"}
    };
    int num_students = sizeof(students) / sizeof(students[0]);

    // Open the file in write mode
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write each student record to the file
    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s %d %s\n", students[i].name, students[i].id, students[i].subject);
    }

    // Close the file
    fclose(file);
}

void parse_student_data(const char *filename) {
                                                                                                                                                 FILE  *file;
    struct Student student;

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    // Read each student record from the file
    while (fscanf(file, "%s %d %s", student.name, &student.id, student.subject) != EOF) {
        // Print student information
        printf("Name: %s, ID: %d, Subject: %s\n", student.name, student.id, student.subject);
    }

    // Close the file
    fclose(file);
}

int main() {
    student_data("student_data.txt");
    printf("Student records written to file successfully.\n");

    parse_student_data("student_data.txt");

    return 0;
}
