#include "insertion_sort.h" //This line includes the header file insertion_sort.h, which contains the function prototype for the insertion_sort function. This allows the compiler to know about the function signature and type declarations without needing to see the actual implementation.

void insertion_sort(int arr[], int n) {//This line defines the insertion_sort function. It specifies that the function takes an integer array arr[] and its size n as parameters and returns nothing (void). The function implementation begins here.
    int i, key, j;//This line declares integer variables i, key, and j which will be used as loop counters and temporary storage for elements during the sorting process.
    for (i = 1; i < n; i++) {//This line starts a loop that iterates over each element of the array starting from the second element (index 1) up to the last element (index n-1). The variable i represents the current element being considered for insertion.
        key = arr[i];// This line stores the value of the current element (arr[i]) in the variable key. This element will be compared and inserted into its correct position in the sorted subarray.
        j = i - 1;//This line initializes j to the index of the element immediately before the current element i. This index will be used to compare key with the elements of the sorted subarray to its left.

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {//This line starts a while loop that continues as long as j is greater than or equal to 0 (ensuring we don't go out of bounds) and the element at index j is greater than key. This loop shifts elements of the sorted subarray to the right until an appropriate position for key is found.
            arr[j + 1] = arr[j];//This line moves the element at index j one position to the right.
            j = j - 1;//This line decrements j to move to the previous element in the sorted subarray for further comparisons.
        }
        arr[j + 1] = key;//This line inserts key into its correct position in the sorted subarray, shifting elements as necessary to make space.
    }
}


//secure code  - because it checks for invalid input sizes to prevent buffer overflow and doesn't allow the user to input more elements than the maximum array size.
