#ifndef HEAPSORT_H//This is a preprocessor directive that checks if the given macro is not defined. In this case, it checks if HEAPSORT_H is not defined.
#define HEAPSORT_H// This is a preprocessor directive used to define macro HEAPSORT_H

#include <stddef.h> //This includes the standard header file stddef.h, which provides the definition of the size_t type used for representing sizes of objects.

void heap_sort(int arr[], size_t n);//This specifies the return type of the function, which is void indicating that the function does not return any value. This is the name of the function being declared.These are the parameters of the function. arr[] is an array of integers (the array to be sorted), and size_t n is the size of the array.

#endif //This is a preprocessor directive that marks the end of the conditional block started by #ifndef. It indicates the end of the include guard.
