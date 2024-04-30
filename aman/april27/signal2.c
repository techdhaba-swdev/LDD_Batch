#include <stdio.h>
#include <stdlib.h>
 
void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
FILE* safe_fopen(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return file;
}
 
int main() {
 
    int* arr = safe_malloc(10 * sizeof(int));
    FILE* fp = safe_fopen("test.txt", "r");
    int* ptr = NULL;
    if (ptr != NULL) {
        *ptr = 10; 
    }
 
    free(arr);
    fclose(fp);
 
    return 0;
}
