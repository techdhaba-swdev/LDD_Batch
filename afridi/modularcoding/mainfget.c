#include <stdio.h>
#include <string.h>

int main() {
    char username[11]; // Allocate 11 bytes for username (including null terminator)
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin); // Read input with bounds checking

    // Remove trailing newline character if present
    size_t len = strlen(username);
    if (len > 0 && username[len - 1] == '\n') {
        username[len - 1] = '\0';
    }

    // Code that uses the username variable
    printf("Username: %s\n", username);

    return 0;
}
