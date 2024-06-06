#ifndef QUICKSORT_H
#define QUICKSORT_H

// Function to swap two elements
void swap(int* a, int* b);

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high);

// Function to perform the QuickSort algorithm
void quickSort(int arr[], int low, int high);

// Function to print an array
void printArray(int arr[], int size);

#endif // QUICKSORT_H

