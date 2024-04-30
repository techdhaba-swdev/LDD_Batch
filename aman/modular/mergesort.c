#include "mergesort.h"//    This line includes the header file "mergesort.h", which likely contains function declarations and possibly other preprocessor directives or definitions necessary for the program.

void merge(int arr[], size_t left, size_t mid, size_t right) {//    This line starts the definition of the merge function, which merges two sorted subarrays into one sorted array.It takes four parameters  - arr[] The array to be sorted.left is  The starting index of the first subarray.mid is The ending index of the first subarray and the starting index of the second subarray.right as The ending index of the second subarray.
    size_t n1 = mid - left + 1;//    These lines calculate the sizes of the two subarrays to be merged.
    size_t n2 = right - mid;

    
    int L[n1], R[n2];//    These lines declare two temporary arrays L and R to hold the elements of the two subarrays to be merged.

    
    for (size_t i = 0; i < n1; i++)//    This loop copies the elements from the left subarray of arr to the L array.
        L[i] = arr[left + i];
    for (size_t j = 0; j < n2; j++)//    This loop copies the elements from the right subarray of arr to the R array.
        R[j] = arr[mid + 1 + j];

    size_t i = 0, j = 0, k = left;//    These lines initialize three indices: i for the left subarray, j for the right subarray, and k for the merged array.
    while (i < n1 && j < n2) {//    This loop merges the elements of the left and right subarrays into the original array arr in sorted order.
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
//    These two loops handle the remaining elements in case one subarray is exhausted before the other.
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], size_t left, size_t right) {//    This line starts the definition of the merge_sort function, which is a recursive function that implements the merge sort algorithm.It takes three parametersthat is -arr[] is The array to be sorted.left as The starting index of the subarray to be sorted.right as The ending index of the subarray to be sorted.
    if (left < right) {//    This line checks if there are at least two elements in the subarray to be sorted. If there's only one element, the subarray is considered already sorted, so no further action is needed.
        size_t mid = left + (right - left) / 2;//    This line calculates the middle index of the subarray.

        merge_sort(arr, left, mid);//    These lines recursively call merge_sort on the left and right halves of the subarray.
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);//    This line calls the merge function to merge the sorted left and right halves of the subarray.
    }
}
//secure code -The merge_sort function ensures that the parameters left and right are within valid bounds. This helps prevent potential buffer overflows or accessing memory out of bounds.

//Stack Allocation Temporary arrays L and R are allocated on the stack using the sizes n1 and n2 calculated from the input, rather than dynamically allocating memory. Stack allocation can be safer than dynamic allocation as it's less prone to memory leaks and exploitation if done correctly.

//Bounds Checking The while loops in the merge function ensure that array indices (i, j, k) never go out of bounds (n1, n2) during the merge process, preventing potential buffer overflows.

//Recursion Depth Control The merge_sort function checks if the array to be sorted has more than one element before recursively calling itself. This helps prevent stack overflow errors due to excessive recursion.

//Algorithmic ComplexityMerge sort has a worst-case time complexity of O(n log n), which is relatively efficient for sorting large datasets. Efficient algorithms can indirectly contribute to security by reducing the attack surface and preventing denial-of-service attacks caused by inefficient code.
//Header File Including header files (#include "mergesort.h") ensures that function prototypes and other necessary declarations are available at compile-time, promoting code modularity and reducing the risk of errors or vulnerabilities.
