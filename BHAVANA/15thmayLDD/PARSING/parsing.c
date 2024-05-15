#include <stdio.h>

// Define a constant for the maximum number of students
#define MAX_STUDENTS 100

// Define a structure to represent a student
struct Student { 
    char studentName[50]; // Name of the student
    int studentID; // ID of the student
    char studentSubject[50]; // Subject of the student
};

// Main function
int main() {
    // Declare an array to store student data
    struct Student studentList[MAX_STUDENTS]; // List to store student data
    int numStudents = 0; // Number of students read from the file

    // Open the data file
    FILE *dataFile = fopen("student_data.txt", "r");
    // Check if file opening was successful
    if (dataFile == NULL) {
        printf("Error: Unable to open data file.\n");
        return 1; // Exit program with error code
    }

    // Read student data from the file
    while (fscanf(dataFile, "%s %d %s", studentList[numStudents].studentName, &studentList[numStudents].studentID, studentList[numStudents].studentSubject) != EOF) {
        numStudents++; // Increment the number of students read
        // Check if maximum number of students reached
        if (numStudents >= MAX_STUDENTS) {
            printf("Warning: Maximum number of students reached.\n");
            break; // Exit the loop
        }
    }

    // Close the file
    fclose(dataFile);

    printf("Student Data:\n"); // Print header for student data
    printf("-------------------------------------------------\n"); // Print horizontal line separator
    printf("| %-10s | %-10s | %-20s |\n", "Name", "ID", "Subject"); // Print column headers with proper alignment
    printf("-------------------------------------------------\n"); // Print horizontal line separator
    for (int i = 0; i < numStudents; i++) {
        printf("| %-10s | %-10d | %-20s |\n", studentList[i].studentName, studentList[i].studentID, studentList[i].studentSubject); // Print student data with proper alignment
    }
    printf("-------------------------------------------------\n"); // Print horizontal line separator
    return 0; // Exit program with success code
}
