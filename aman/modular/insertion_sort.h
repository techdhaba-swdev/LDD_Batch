#ifndef INSERTION_SORT_H //this is a preprocessor directive that checks if the macro INSERTION_SORT_H is not defined. If it's not defined, it proceeds with the code inside the #ifndef block. This construct is used to prevent multiple inclusions of the header file, ensuring that it's included only once in a compilation unit.
#define INSERTION_SORT_H //If the macro INSERTION_SORT_H was not defined previously, this line defines it now. This ensures that subsequent attempts to include the header file won't enter the #ifndef block, preventing multiple inclusions.

void insertion_sort(int arr[], int n); // This line declares the function prototype for the insertion_sort function. It specifies that the function takes an integer array arr[] and its size n as parameters and returns nothing (void). This declaration allows other source files that include this header to use the insertion_sort function without needing to know its implementation details.

#endif //: This line closes the conditional compilation block started by #ifndef
