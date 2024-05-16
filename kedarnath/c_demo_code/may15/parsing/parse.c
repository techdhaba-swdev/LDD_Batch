#include <stdio.h>
#include <stdlib.h>

// Function to write student data into a file
void write_student_data(const char *filename, const char *data[], int num_students) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%s\n", data[i]);
    }

    fclose(file);
}

// Function to parse and print student data from a file
void parse_and_print_student_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    char line[100]; // Assuming each line in the file is at most 100 characters long
    while (fgets(line, sizeof(line), file)) {
	    
        printf("Student data: %s", line);
    }

    fclose(file);
}

int main() {
    // Example student data
    const char *students[] = {
        "John Doe,101,Math",
        "Jane Smith,102,History",
        "Alice Johnson,103,Science"
    };

    // File to store student data
    const char *filename = "student_data.txt";

    // Write student data into the file
    write_student_data(filename, students, sizeof(students) / sizeof(students[0]));

    // Parse and print student data from the file
    printf("Student data from file:\n");
    parse_and_print_student_data(filename);

    return 0;
}




