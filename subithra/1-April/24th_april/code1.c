#include <stdio.h>

int main() {
    int user_id = 1000000000000; // May overflow on 32-bit systems
    user_id++; // Could become negative due to overflow
    if (user_id > 100) { // Check might fail due to unexpected value
        printf("user id:%d\n",user_id); // Grant access (potentially unintended)
    }
    printf("user id:%d\n",user_id);
    return 0;
}
