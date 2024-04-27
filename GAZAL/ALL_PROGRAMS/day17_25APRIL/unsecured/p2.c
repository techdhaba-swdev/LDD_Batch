#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char command[100];
    char argument[50];
    
    if (argc != 2) {
        printf("Usage: %s <argument>\n", argv[0]);
        return 1;
    }
    
    strcpy(argument, argv[1]); // Unsafe usage of strcpy
    
    // Vulnerable command execution
    sprintf(command, "ping %s", argument);
    
    // Execute the command
    system(command);
    
    return 0;
}