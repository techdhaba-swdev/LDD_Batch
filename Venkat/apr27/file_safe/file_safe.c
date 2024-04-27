#include <stdio.h>
#include <stdlib.h>

 

// Function to safely allocate memory
void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

 

// Function to safely open a file
FILE* safe_fopen(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return file;
}

 

int main() {
    // Memory allocation
    int* arr = safe_malloc(10 * sizeof(int));

 

    //  File I/O
    FILE* fp = safe_fopen("test.txt", "r");

 

    // Techniques to avoid segmentation faults
    int* ptr = NULL;
    if (ptr != NULL) {
        *ptr = 10; // This line will not be executed, preventing segmentation fault
    }

 

    free(arr);
    fclose(fp);

 

    return 0;
}
