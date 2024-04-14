#include <stdio.h>

// Function to swap the values pointed to by two integer pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
   
    printf("Before swapping: x = %d, y = %d\n", x, y);
   
    // Call swap function to swap the values of x and y
    swap(&x, &y);
   
    printf("After swapping: x = %d, y = %d\n", x, y);
   
    return 0;
}
