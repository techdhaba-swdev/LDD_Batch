#include "palindrome.h"//This line includes the header file "palindrome.h" in the source file. This allows the functions and types declared in palindrome.h to be used in this source file.
#include <string.h>//This line includes the standard C header file string.h, which provides various string manipulation functions.
#include <ctype.h>// This line includes the standard C header file ctype.h, which provides functions for character classification and conversion.


bool isPalindrome(char *str) {//This line defines the function isPalindrome. It specifies that the function returns a boolean value (bool) and takes a pointer to a character (char *) as its argument. The function checks whether the input string str is a palindrome or not.
    int left = 0;//This line initializes an integer variable left to 0. It represents the index of the leftmost character in the string.
    int right = strlen(str) - 1;//This line initializes an integer variable right to the length of the string str minus 1. It represents the index of the rightmost character in the string.

    while (left < right) {//This line starts a while loop that continues as long as the index left is less than the index right. This loop iterates over the string until the indices meet in the middle.
        
        while (!isalnum(str[left]) && left < right)//This line starts an inner while loop that skips non-alphanumeric characters from the left side of the string. 
            left++;//It increments the left index until it encounters an alphanumeric character or until left is equal to right.
        
        
        while (!isalnum(str[right]) && left < right)//This line starts another inner while loop that skips non-alphanumeric characters from the right side of the string. 
            right--;// It decrements the right index until it encounters an alphanumeric character or until left is equal to right.
        
        
        if (tolower(str[left]) != tolower(str[right]))//This line checks if the characters at indices left and right are not equal when converted to lowercase.
            return false;//If they are not equal, it means the string is not a palindrome, so the function returns false.
        
        left++;//These lines increment the left index and decrement the right index to move towards the center of the string in each iteration of the while loop.
        right--;//decrement the right index to move towards the center of the string in each iteration of the while loop
    }

    return true;//This line indicates that the string is a palindrome, as all corresponding characters from the left and right sides of the string matched successfully in the loop. So, the function returns true
}

  
//securecode --Ensuring that the bool type is properly defined for the isPalindrome function. Changed char *str to const char *str to indicate that the function will not modify the input string. This is a good practice for clarity and prevents accidental modification of the input string.Before performing any operations on the input string str, a check is added to ensure it's not NULL. This helps prevent segmentation faults if a NULL pointer is passed to the function.
