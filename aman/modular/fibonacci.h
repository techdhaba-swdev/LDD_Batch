#ifndef FIBONACCI_H //This is a preprocessor directive that stands for "if not defined". It checks if the symbol following it has not been defined previously in the file.
#define FIBONACCI_H //This is another preprocessor directive used to define a macro. In this case, we are defining FIBONACCI_H to indicate that it's now defined. This prevents the header file from being included more than once in the same translation unit, which can cause compilation errors due to duplicate declarations.

unsigned long long fibonacci(int n);//This is a function declaration. It declares a function named fibonacci that takes an integer n as its argument and returns an unsigned long long integer. The function calculates the nth Fibonacci number. This declaration serves as an interface for the function, allowing other source files to use it without needing to know its implementation details.

#endif //This preprocessor directive marks the end of the conditional block that started with #ifndef. It closes the conditional inclusion of the header file.

