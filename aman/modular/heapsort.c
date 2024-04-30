#include "heapsort.h"//This line includes the header file heap_sort.h in the current source file. It allows us to use the function declarations and any other declarations present in heapsort.h.

void heapify(int arr[], size_t n, size_t i) {//This specifies the return type of the function heapify, which is void indicating that the function does not return any value.This is the name of the function being defined.These are the parameters of the function. arr[] is an array of integers (the array to be heapified), size_t n is the size of the heap, and size_t i is the index of the current node in the heap.
    size_t largest = i; //This initializes a variable largest to the index i, assuming initially that the current node is the largest.
    size_t left = 2 * i + 1; //This calculates the index of the left child node of the current node.
    size_t right = 2 * i + 2; //This calculates the index of the right child node of the current node.

 
    if (left < n && arr[left] > arr[largest])//This condition checks if the left child of the current node exists (left < n) and if it is greater than the current largest node.
        largest = left;//If the condition is true, largest is updated to the index of the left child.

    
    if (right < n && arr[right] > arr[largest])//This condition checks if the right child of the current node exists (right < n) and if it is greater than the current largest node.
        largest = right;//If the condition is true, largest is updated to the index of the right child.

    
    if (largest != i) {//This condition checks if the current node is not the largest among the parent and its children.
        
        int temp = arr[i];//This temporarily stores the value of the current node.
        arr[i] = arr[largest];//The value of the largest child node is assigned to the current node.
        arr[largest] = temp;//The value stored in temp (originally the current node value) is assigned to the position of the largest child node.

        
        heapify(arr, n, largest);// This recursively calls heapify on the affected sub-tree to ensure that the heap property is maintained.
    }
}


void heap_sort(int arr[], size_t n) {//This line defines the heap_sort function, which is responsible for sorting the array using the heap sort algorithm. It takes two parameters: arr[], an array of integers to be sorted, and n, the size of the array.
    
    for (int i = n / 2 - 1; i >= 0; i--)//This for loop iterates through the array elements from the last non-leaf node to the root node of the heap. It starts from n / 2 - 1 because it is the index of the last non-leaf node in the heap
        heapify(arr, n, i);//Within the loop, the heapify function is called to heapify the subtree rooted at index i.

    
    for (int i = n - 1; i > 0; i--) {//This for loop iterates through the elements of the array in reverse order, starting from the last element (n - 1) and ending at the second element (index 1). The loop skips the first element (index 0) because it represents the root of the heap.
 
        int temp = arr[0];//This line temporarily stores the value of the root element of the heap.
        arr[0] = arr[i];//The value of the last element of the heap is moved to the root position.
        arr[i] = temp;//The value stored in temp (originally the root node value) is moved to the position of the last element of the heap.

       
        heapify(arr, i, 0);//After extracting the maximum element from the heap, this line calls the heapify function to restore the heap property on the reduced heap (excluding the last extracted element). It ensures that the largest remaining element becomes the root of the heap.
    }
}


//secure code -- avoiding buffer overflows
