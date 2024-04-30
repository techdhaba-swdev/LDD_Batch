#ifndef MERGESORT_H//This is a preprocessor directive that checks if the given macro is not defined. In this case, it checks if MERGE_SORT_H is not defined.
#define MERGESORT_H//This is a preprocessor directive used to define macros and  mergesort.h macro is defined, indicating that the contents of the header file are being included.

#include <stddef.h> //This is a preprocessor directive used to include the contents of another file in the current fileand includes the standard header file stddef.h, which provides the definition of the size_t type used for representing sizes of objects.

void merge_sort(int arr[], size_t n);//This line declares a function named merge_sort that takes an array of integers arr[] and its size n as parameters. It's used to initiate the merge sort algorithm.
void merge(int arr[], size_t left, size_t mid, size_t right);//This line declares a function named merge that takes an array of integers arr[] and three indices left, mid, and right as parameters. It's used to merge two sorted subarrays into a single sorted array.

#endif //This is a preprocessor directive that marks the end of the conditional block started by #ifndef. It indicates the end of the include guard.
