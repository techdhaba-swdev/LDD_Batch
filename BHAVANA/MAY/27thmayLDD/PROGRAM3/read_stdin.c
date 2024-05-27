#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];

    // Read from standard input and display on standard output
    printf("Enter text (Ctrl+D to end input):\n");
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        printf("%s", buffer);
    }

    // Check for reading errors (if any)
    if (ferror(stdin)) {
        perror("Error reading from standard input");
        exit(EXIT_FAILURE);
    }

    return 0;
}
