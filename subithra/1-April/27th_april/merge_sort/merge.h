//This line starts an include guard to prevent the header file from being included more than once in the same compilation unit. If MERGE_SORT_H is not defined, the contents of the file will be processed. If it is defined, the contents will be skipped.
#ifndef MERGE_SORT_H 
//This line defines the macro MERGE_SORT_H, which is used as the guard symbol. If it's not defined, it's defined here, preventing subsequent inclusions of the header from being processed.
#define MERGE_SORT_H
//This line includes the standard header file stddef.h, which contains the definition of size_t. size_t is an unsigned integer type used for storing the size of objects. This header is included because merge_sort function takes a size_t parameter.
#include <stddef.h> // for size_t

// This line declares the function merge_sort, which is used to perform the merge sort algorithm on an array arr of size n. It takes an integer array arr and a size n as parameters. The void return type indicates that the function does not return a value.
void merge_sort(int arr[], size_t n);

#endif /* MERGE_SORT_H */ 
// This prevents the contents from being processed more than once in the same compilation unit, which could lead to errors such as redefinition of functions or duplicate declarations.