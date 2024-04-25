#include <stdio.h>
int main() {
    char buffer[10];
    scanf("%s", buffer); // Unsafe input
    printf("You entered: %s\n", buffer);
    return 0;
}
