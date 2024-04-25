#include"example.h" // adding the header file example.h
int main() {
    int num1 = 10; // declearing and initializing varible num1 with value
    int num2 = 20; // declearing and initializing varible num2 with value

    // Function call with meaningful variable names
    int sum = add(num1, num2); // calling add method present inside example.c file and passing two integer argument and stored retuned alue in sum variable

    // Clear and concise message
    print_message("The sum is: "); //calling print_message method which takes character pointer and here we passes the one message as an argument this method is also present inside example.c
    
    printf("%d\n", sum); // printing the retuned value of add function which is strored inside sum variable

    return 0;  // Indicate successful program termination
}

