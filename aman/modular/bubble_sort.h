#ifndef BUBBLE_SORT_H//This is a preprocessor directive that stands for "if not defined". It checks if the symbol following it has not been defined previously in the file.
#define BUBBLE_SORT_H// This is another preprocessor directive used to define a macro. In this case, we are defining BUBBLE_SORT_H to indicate that it's now defined. This prevents the header file from being included more than once in the same translation unit, which can cause compilation errors due to duplicate declarations.

void bubbleSort(int arr[], int size);//This is a function declaration. It declares a function named bubbleSort that takes an array of integers arr and its size size as its arguments. The function sorts the array using the Bubble Sort algorithm. This declaration serves as an interface for the function, allowing other source files to use it without needing to know its implementation details.

#endif //This preprocessor directive marks the end of the conditional block that started with #ifndef. It closes the conditional inclusion of the header file.

