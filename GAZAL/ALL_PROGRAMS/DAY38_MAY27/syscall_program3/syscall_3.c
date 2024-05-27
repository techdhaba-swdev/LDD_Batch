#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];

    // Read data from standard input
    printf("enter input: ");
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        perror("Failed to read from standard input");
        exit(EXIT_FAILURE);
    }

    // Write data to standard output
     printf("the text you entered is: ");
    if (fputs(buffer, stdout) == EOF) {
        perror("Failed to write to standard output");
        exit(EXIT_FAILURE);
    }

    return 0;
}
