#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define FILENAME "example.txt"

int main() {
    struct stat fileStat;

    // Get file status
    if (lstat(FILENAME, &fileStat) < 0) {
        perror("Failed to get file status");
        exit(EXIT_FAILURE);
    }

    // Display inode number and block size
    printf("File: %s\n", FILENAME);
    printf("Inode number: %ld\n", fileStat.st_ino);
    printf("Block size: %ld bytes\n", fileStat.st_blksize);

    return 0;
}

	

