#include <stdio.h>    
#include <sys/stat.h> 

int main() {
    struct stat file_data;  

    
    if (stat("badri.txt", &file_data) == -1) {  
        perror("Failed to get file information");  
        return 1;  
    }

    
    printf("Inode number: %ld\n", file_data.st_ino);  
    printf("Block size: %ld bytes\n", file_data.st_blksize);  
    return 0;  
}
