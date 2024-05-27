#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void display_file_info(const char *file_path) {
    struct stat file_stat;

    // Use lstat to get file information
    if (lstat(file_path, &file_stat) == -1) {
        perror("Failed to get file status");
        exit(EXIT_FAILURE);
    }

    // Display the inode number and block size
    printf("File: %s\n", file_path);
    printf("Inode Number: %lu\n", file_stat.st_ino);
    printf("Block Size: %ld\n", file_stat.st_blksize);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    display_file_info(argv[1]);

    return 0;
}


