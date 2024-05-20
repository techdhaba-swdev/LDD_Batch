#include "printArray.h"
#include <stdio.h>

// Function to print the elements of an array
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}
