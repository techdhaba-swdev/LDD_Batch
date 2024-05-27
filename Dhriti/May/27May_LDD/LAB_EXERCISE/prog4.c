#include <stdio.h>    
#include <sys/stat.h> // Include system call for retrieving file information

int main() {
    struct stat file_info;  // Structure to hold file information

    // Call stat system call to get file information
    if (stat("example.txt", &file_info) == -1) {  // Check if stat call failed
        perror("Failed to get file information");  
        return 1;  // Exit with failure 
    }

    // Display file information
    printf("Inode number: %ld\n", file_info.st_ino);  // Print inode number
    printf("Block size: %ld bytes\n", file_info.st_blksize);  // Print block size

    return 0;  
}
