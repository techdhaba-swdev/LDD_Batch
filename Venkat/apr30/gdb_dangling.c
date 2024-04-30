#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void allocate_and_modify(int **ptr) {
    int *temp = (int *)malloc(sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    *temp = 10;
    *ptr = temp;
}

int main() {
    int *x = NULL;
    clock_t start = clock();
    allocate_and_modify(&x);
    clock_t end = clock();
    printf("Modified value: %d\n", *x);
    free(x);
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
	

