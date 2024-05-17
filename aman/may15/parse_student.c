#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    int id;
    char subject[MAX_LEN];
} Student;

int main() {
    FILE *file;
    char line[MAX_LEN];
    Student student;

    // Open the file for reading
    file = fopen("student.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read and parise each line in the file
    while (fgets(line, sizeof(line), file)) {
        // Parse the line into name, id, and subject
        if (sscanf(line, "%s %d %s", student.name, &student.id, student.subject) == 3) {
            // Print the parsed data
            printf("Name: %s, ID: %d, Subject: %s\n", student.name, student.id, student.subject);
        } else {
            printf("Error parsing line: %s\n", line);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}
