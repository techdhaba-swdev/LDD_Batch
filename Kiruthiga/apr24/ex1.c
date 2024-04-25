#include <stdio.h>

int main() {
    unsigned long long user_id = 100000000000;
    user_id++; // No risk of overflow
    if (user_id > 100) {
        // Safe check
        printf("Access granted\n");
    }
    return 0;
}
