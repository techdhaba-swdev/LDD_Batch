#ifndef STACK_H //is a preprocessor directive that checks if the symbol STACK_H has not been defined yet.
#define STACK_H // is a preprocessor directive that defines the symbol STACK_H.

#include <stdbool.h> //defines the Boolean data type along with its two possible values, true and false, which are used in this header file for function return types and conditions.

// Define maximum size of the stack
#define MAX_SIZE 100//is a preprocessor directive that defines the constant MAX_SIZE with a value of 100.

// Structure to represent the stack
typedef struct {  
    int items[MAX_SIZE];
    int top;
} Stack;

// Function prototypes     These lines declare the function prototypes for the stack operations.
 //   Each function takes a pointer to a Stack structure (Stack *s) as its argument, allowing the functions to operate on the stack.
   // The functions provide operations such as initialization (initialize), checking if the stack is full (isFull), checking if the stack is empty (isEmpty), pushing an element onto the stack (push), popping an element from the stack (pop), and peeking at the top element of the stack (peek).
void initialize(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);

#endif //is a preprocessor directive that marks the end of the conditional inclusion started by #ifndef.
//This line terminates the conditional inclusion block, ensuring that the contents of stack.h are only included once.
