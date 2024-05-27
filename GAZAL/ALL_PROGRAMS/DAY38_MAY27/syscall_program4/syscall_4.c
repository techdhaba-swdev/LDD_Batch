#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FILENAME "example.txt"

int main() {
    struct stat file_stat;

    
    if (lstat(FILENAME, &file_stat) == -1) {
        perror("Failed to get file status");
        exit(EXIT_FAILURE);
    }

   
    printf("File: %s\n", FILENAME);
    printf("Inode number: %lu\n", (unsigned long)file_stat.st_ino);
    printf("Block size: %ld bytes\n", (long)file_stat.st_blksize);

    return 0;
}
