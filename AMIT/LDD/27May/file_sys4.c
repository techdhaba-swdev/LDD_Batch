#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <myfile.txt>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    struct stat file_info;

    if (stat(filename, &file_info) == -1) {
        perror("Error getting file information");
        return 1;
    }

    printf("File: %s\n", filename);
    printf("Inode number: %lu\n", (unsigned long)file_info.st_ino);
    printf("Block size: %ld bytes\n", (long)file_info.st_blksize);

    return 0;
}

