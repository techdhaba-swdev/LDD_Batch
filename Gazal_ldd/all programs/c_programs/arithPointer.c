#include <stdio.h>

int main() {

 int arr[] = {10, 20, 30, 40, 50};
   
    int *ptr = arr; 

    printf("First element: %d\n", *ptr);
    printf("Second element: %d\n", *(ptr + 1)); // Accessing the second element
    printf("Third element: %d\n", *(ptr + 2));  // Accessing the third element
    printf("Fourth element: %d\n", *(ptr + 3)); // Accessing the fourth element
    printf("Fifth element: %d\n", *(ptr + 4));  // Accessing the fifth element

    return 0;
}