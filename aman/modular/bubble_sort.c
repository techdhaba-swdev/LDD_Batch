#include "bubble_sort.h"//This line includes the header file "bubble_sort.h" in the source file. This allows the function bubbleSort declared in bubble_sort.h to be used in this source file.

void bubbleSort(int arr[], int size) {//This line defines the function bubbleSort. It specifies that the function returns void, meaning it does not return any value, and takes two arguments: an integer array arr and its size size. The function sorts the array using the Bubble Sort algorithm.
    for (int i = 0; i < size - 1; i++) {//This line starts a loop that iterates from i = 0 to size - 2. It represents the pass number of the outer loop in the Bubble Sort algorithm, where each pass compares adjacent elements and swaps them if they are in the wrong order.
        for (int j = 0; j < size - i - 1; j++) {//This line starts a nested loop that iterates from j = 0 to size - i - 2. It represents the comparison of adjacent elements within each pass of the outer loop. The - i part reduces the number of iterations in each pass, as the largest elements "bubble up" to their correct positions at the end of the array after each pass.
            if (arr[j] > arr[j + 1]) {//This line checks if the current element arr[j] is greater than the next element arr[j + 1]. If this condition is true, it means the elements are in the wrong order, and they need to be swapped
                // Swap arr[j] and arr[j + 1]
		// These lines perform the swapping of arr[j] and arr[j + 1]. The current value of arr[j] is stored in a temporary variable temp, then arr[j] is assigned the value of arr[j + 1], and finally, arr[j + 1] is assigned the value of temp.
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

