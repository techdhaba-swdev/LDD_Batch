#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *file;
    char buffer[BUFFER_SIZE];

    // Open the file in read-only mode
    file = fopen("source.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Read and display the file line by line
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }

    // Check for reading errors
    if (ferror(file)) {
        perror("Error reading from file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Close the file
    if (fclose(file) != 0) {
        perror("Failed to close file");
        exit(EXIT_FAILURE);
    }

    return 0;
}
