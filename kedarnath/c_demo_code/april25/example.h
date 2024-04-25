#ifndef EXAMPLE_H_
#define EXAMPLE_H_ 

/* Header Guard: The #ifndef and #define directives with EXAMPLE_H_ create a header guard to prevent multiple inclusions of the same header file, ensuring code is compiled only once.
extern Keyword: Function prototypes use the extern keyword to declare their existence without providing definitions. This avoids violating the MISRA C rule against function definitions in header files */ 


#include<stdio.h>

// Function prototypes for add and print_message
extern int add(int x, int y);
extern void print_message(const char *message);

/* const Qualifier: The const char *message parameter in print_message explicitly declares the string pointer as constant, preventing accidental modification within the function, which aligns with MISRA C's preference for avoiding undefined behavior */

#endif 

