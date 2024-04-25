#include <stdio.h>

int main() {
    int secret;
    int authenticated = 1;
    
    if (authenticated) {
        printf("Secret value: %d\n", secret); // Uninitialized variable
    } else {
        printf("Access denied.\n");
    }
    
    return 0;
}
