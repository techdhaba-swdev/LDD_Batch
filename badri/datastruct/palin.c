#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a palindrome
bool isPalindrome(const char *str) {
    int length = strlen(str);
    int i, j;
   
    // Compare characters from start and end of the string
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            // If characters don't match, it's not a palindrome
            return false;
        }
    }
   
    // If all characters match, it's a palindrome
    return true;
}

int main() {
    char str1[] = "radar";
    char str2[] = "hello";

    if (isPalindrome(str1)) {
        printf("%s is a palindrome.\n", str1);
    } else {
        printf("%s is not a palindrome.\n", str1);
    }

    if (isPalindrome(str2)) {
        printf("%s is a palindrome.\n", str2);
    } else {
        printf("%s is not a palindrome.\n", str2);
    }

    return 0;
}
