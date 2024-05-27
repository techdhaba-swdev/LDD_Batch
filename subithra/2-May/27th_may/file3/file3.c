#include <stdio.h>

int main() {
    char input[256];
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    printf("You entered: %s\n", input);
    return 0;
}
