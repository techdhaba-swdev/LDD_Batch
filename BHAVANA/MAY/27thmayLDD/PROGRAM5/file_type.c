#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void display_file_type(const char *file_path) {
    struct stat file_stat;

    // Use lstat to get file information
    if (lstat(file_path, &file_stat) == -1) {
        perror("Failed to get file status");
        exit(EXIT_FAILURE);
    }

    // Determine the type of the file
    printf("File: %s\n", file_path);
    printf("File Type: ");
    if (S_ISREG(file_stat.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(file_stat.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISCHR(file_stat.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(file_stat.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(file_stat.st_mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISSOCK(file_stat.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    display_file_type(argv[1]);

    return 0;
}


