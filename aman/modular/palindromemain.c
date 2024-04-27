#include <stdio.h>//This line includes the standard input-output header file stdio.h, which provides functions like printf() and scanf() for input and output operations.
#include "palindrome.h"//This line includes the header file "palindrome.h" in the source file. It allows us to use the function isPalindrome declared in palindrome.h and defined in palindrome.c.

int main() {//This line defines the main function, which is the entry point of the program. Execution of the program begins from here.
    char str[100];//This line declares an array str of characters with a size of 100. It will be used to store the input string entered by the user.
    printf("Enter a string: ");//This line prints the prompt asking the user to enter a string onto the standard output (typically the console).
    scanf("%s", str);//This line reads a string input from the user and stores it in the character array str. The %s format specifier tells scanf to read a string until it encounters whitespace.

    if (isPalindrome(str))//This line checks if the entered string str is a palindrome by calling the isPalindrome function. If the function returns true (indicating that the string is a palindrome), the condition evaluates to true, and the subsequent block of code is executed.
        printf("%s is a palindrome.\n", str);//If the entered string is a palindrome, this line prints a message confirming that the string is indeed a palindrome.
    else// If the condition in the if statement above evaluates to false (indicating that the string is not a palindrome), this line executes.
        printf("%s is not a palindrome.\n", str);//    This line prints a message indicating that the entered string is not a palindrome.



    return 0;//This line signifies the successful termination of the main function and the program as a whole. It returns an exit status of 0 to the operating system, indicating that the program executed successfully.
}

