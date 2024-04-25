#include<stdio.h>

void main()
{


char username[10]; // Only 10 bytes allocated
printf("Enter username: ");
gets(username); // Unbounded input can overflow the buffer
 
// Code that uses the username variable could be compromised
}

