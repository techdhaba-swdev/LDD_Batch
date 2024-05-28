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

    // Check the type of file
    if (S_ISREG(fileStat.st_mode)) {
        printf("%s is a regular file.\n", FILENAME);
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("%s is a directory.\n", FILENAME);
    } else if (S_ISCHR(fileStat.st_mode)) {
        printf("%s is a character device.\n", FILENAME);
    } else if (S_ISBLK(fileStat.st_mode)) {
        printf("%s is a block device.\n", FILENAME);
    } else if (S_ISFIFO(fileStat.st_mode)) {
        printf("%s is a FIFO/pipe.\n", FILENAME);
    } else if (S_ISLNK(fileStat.st_mode)) {
        printf("%s is a symbolic link.\n", FILENAME);
    } else if (S_ISSOCK(fileStat.st_mode)) {
        printf("%s is a socket.\n", FILENAME);
    } else {
        printf("%s is an unknown file type.\n", FILENAME);
    }

    return 0;
}

	

