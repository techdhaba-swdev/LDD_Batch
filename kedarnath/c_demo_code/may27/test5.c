#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct stat file_stat;
    if (stat(argv[1], &file_stat) == -1) {
        perror("Failed to get file statistics");
        exit(EXIT_FAILURE);
    }

    printf("File: %s\n", argv[1]);
    printf("Inode number: %ld\n", (long) file_stat.st_ino);
    printf("Block size: %ld\n", (long) file_stat.st_blksize);

    return 0;
}



