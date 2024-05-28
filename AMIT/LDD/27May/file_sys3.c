#include <stdio.h>

int main() {
    char input[100]; // Adjust buffer size as needed

    printf("Enter text (Ctrl+D or Ctrl+Z to end input):\n");

    while (fgets(input, sizeof(input), stdin) != NULL) {
        printf("You entered: %s", input);
    }

    printf("\nEnd of input.\n");

    return 0;
}

