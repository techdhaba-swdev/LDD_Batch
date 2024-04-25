#include <stdio.h>
#include <stdlib.h>

int main() {
    int user_id = 10000000000;
    
    user_id++;
    
    if (user_id > 100) {
        // Grant access (potentially unintended)
        printf("Access granted\n");
    }
    
    printf("%d\n",user_id);
    
    int* ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("%d\n%u\n",*ptr,ptr);
    *ptr = 42;
    printf("%d\n%u\n",*ptr,ptr);
    free(ptr); // Free dynamically allocated memory
    printf("%d\n%u\n",*ptr,ptr);
    *ptr = 42;
    printf("%d\n%u\n",*ptr,ptr);

    return 0;
}




