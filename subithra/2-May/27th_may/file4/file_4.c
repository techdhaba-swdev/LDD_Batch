#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *file_path = "sample.txt"
    struct stat file_stat;

    // Use the stat system call to get information about the file
    if (stat(file_path, &file_stat) == -1) {
        perror("Error getting file information");
        return 1;
    }

    // Display the inode number and block size of the file
    printf("File: %s\n", file_path);
    printf("Inode number: %lu\n", file_stat.st_ino);
    printf("Block size: %ld bytes\n", file_stat.st_blksize);

    return 0;
}
