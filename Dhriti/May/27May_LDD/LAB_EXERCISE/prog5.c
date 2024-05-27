#include <stdio.h>     
#include <stdlib.h>    
#include <sys/types.h> // Include data types used in system calls
#include <sys/stat.h>  // Include system call for retrieving file status
#include <unistd.h>    

#define FILENAME "example.txt"  

int main() {
    struct stat file_stat;  // Structure to hold file status information

    // Get file status using lstat
    if (lstat(FILENAME, &file_stat) == -1) {  // Check if lstat call failed
        perror("Failed to get file status");  
        exit(EXIT_FAILURE);  
    }

    // Check file type
    if (S_ISREG(file_stat.st_mode))  // Check if regular file
        printf("%s is a regular file.\n", FILENAME);  // Print message indicating regular file
    else if (S_ISDIR(file_stat.st_mode))  // Check if directory
        printf("%s is a directory.\n", FILENAME);  // Print message indicating directory
    else
        printf("%s is of unknown type.\n", FILENAME);  // Print message indicating unknown type

    return 0;  
}
