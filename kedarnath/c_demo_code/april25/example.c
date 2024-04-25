#include"example.h" // adding the header file with name as example.h 

int add(int x, int y) { // providing mehtod implementation of add method which is declaired inside example.h file
    int result = x + y; // performing addition on two number which is came when we call method
    return result;  // Return the calculated sum
}

// Function to print a message with a constant string
void print_message(const char *message) {
    printf("%s", message);
}

