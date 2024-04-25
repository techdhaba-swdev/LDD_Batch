#include<stdio.h> // Include standard input/output header for printf function
#include<stdlib.h> // Include standard library header for exit function
#include"stack.h" // Include the header file containing stack function prototypes

#define MAX_SIZE 100 // Define the maximum size of the stack

static int stack[MAX_SIZE]; // Static array to hold stack elements
static int top = -1; // Variable to keep track of the top of the stack, initialized to -1

void push(int value){ // Function to push (add) an element to the stack
	if(stack_is_full()){ // Check if the stack is full
		printf("stack overflow"); // Print error message if the stack is full
		return; // Return from the function
	}
	stack[++top] = value; // Increment top and add the value to the stack
}

int pop(){ // Function to pop (remove) an element from the stack
	if(stack_is_empty()){ // Check if the stack is empty
		printf("stack underflow\n"); // Print error message if the stack is empty
		exit(EXIT_FAILURE); // Exit the program with failure status
	}
	return stack[top--]; // Return the top element and decrement top
}

bool stack_is_empty(){ // Function to check if the stack is empty
	return top == -1; // Return true if top is -1, indicating an empty stack
}

bool stack_is_full(){ // Function to check if the stack is full
	return top == MAX_SIZE -1; // Return true if top is equal to MAX_SIZE - 1, indicating a full stack
}