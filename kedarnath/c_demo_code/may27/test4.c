#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_LINES 100

int main() {
    char buffer[BUFFER_SIZE];
    char *lines[MAX_LINES];
    int line_count = 0;

    // Read from standard input and store each line
    printf("Enter text (Ctrl+D to end input):\n");
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        if (line_count >= MAX_LINES) {
            fprintf(stderr, "Maximum number of lines exceeded.\n");
            exit(EXIT_FAILURE);
        }
        lines[line_count] = malloc(strlen(buffer) + 1);
        if (lines[line_count] == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        strcpy(lines[line_count], buffer);
        line_count++;
    }

    // Display the stored input
    printf("\nYou entered:\n");
    for (int i = 0; i < line_count; i++) {
        fputs(lines[i], stdout);
        free(lines[i]);  // Free the allocated memory
    }

    return 0;
}



