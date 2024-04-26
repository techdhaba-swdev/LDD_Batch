#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t user_id = 1000000000ULL; // Using unsigned 64-bit integer
    user_id++; // Safe increment without overflow

    // Check if user_id is greater than 100
    if (user_id > 100) {
        // Grant access
        printf("Access granted for user ID %llu\n", user_id);
    } else {
        printf("Access denied for user ID %llu\n", user_id);
    }

    return 0;
}
