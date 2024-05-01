#include <stdio.h>
#include<time.h>
 
int main() {
	clock_t start = clock();
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);  
 
    for (int i = 0; i <= size; i++) {  
        printf("%d ", arr[i]);
    }
    clock_t stop = clock();
    double time_taken = ((double)(stop-start));
    printf("time taken: %f\n", time_taken);
 
    printf("\n");
    return 0;
}
