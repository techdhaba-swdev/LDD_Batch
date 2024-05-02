#include <stdio.h>
#include<time.h>

int main()
{
       clock_t start = clock();
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);  
    for (int i = 0; i < size; i++)
    {  
        printf("%d ", arr[i]);
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}
