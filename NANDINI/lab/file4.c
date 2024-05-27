#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_file>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;

    if (lstat(argv[1], &fileStat) < 0) {
        perror("lstat");
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("Inode Number: %ld\n", (long) fileStat.st_ino);
    printf("Block Size: %ld\n", (long) fileStat.st_blksize);

    return 0;
}
