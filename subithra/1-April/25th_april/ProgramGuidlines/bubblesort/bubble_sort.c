#include "bubble_sort.h" // Include the header file

void bubble_sort(int arr[], size_t n) { // Define bubble sort function
    if (n == 0) return; // If the array is empty, no need to sort
    
    for (size_t i = 0; i < n - 1; i++) { // Outer loop for passes
        for (size_t j = 0; j < n - i - 1; j++) { // Inner loop for comparisons
            if (arr[j] > arr[j + 1]) { // If current element is greater than next element
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
