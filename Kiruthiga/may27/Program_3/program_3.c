#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];

    printf("Enter some text. Press Ctrl+D (Ctrl+Z on Windows) to end:\n");

    // Read from standard input until EOF (Ctrl+D/Ctrl+Z)
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        // Print the read text to standard output
        printf("%s", buffer);
    }

    return 0;
}
