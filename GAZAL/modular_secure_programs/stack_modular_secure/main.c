#include<stdio.h> // Include standard input/output header for printf function
#include "main.h" // Include the header file containing function prototypes

int main(){ // Main function definition
	
	push(10); // Call push function to add value 10 to the stack
	push(20); // Call push function to add value 20 to the stack
	push(30); // Call push function to add value 30 to the stack

	printf("popped value:%d\n",pop()); // Call pop function to remove and print the top value from the stack
	printf("popped value:%d\n",pop()); // Call pop function again to remove and print the top value from the stack

	return 0; // Return 0 to indicate successful completion of the program
}



