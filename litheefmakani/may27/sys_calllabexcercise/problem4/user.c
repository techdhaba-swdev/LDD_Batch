#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define FILENAME "example.txt"

int main() {
    struct stat statbuf;
    int fd;

    // Use lstat to get file information (including block size)
    if (lstat(FILENAME, &statbuf) == -1) {
        perror("lstat failed");
        exit(EXIT_FAILURE);
    }

    // Check if it's a regular file (lstat doesn't work on directories)
    if (!S_ISREG(statbuf.st_mode)) {
        fprintf(stderr, "%s is not a regular file.\n", FILENAME);
        exit(EXIT_FAILURE);
    }

    // Open the file for reading (not strictly necessary, but good practice)
    fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    // Use fstat to get file descriptor information (including inode number)
    if (fstat(fd, &statbuf) == -1) {
        perror("fstat failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Inode number: %ld\n", statbuf.st_ino);  // Print inode number
    printf("Block size: %ld bytes\n", statbuf.st_blksize);  // Print block size

    close(fd);
    return 0;
}
