#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileInfo;
    char *file = "stat.txt";

    // file information
    if (stat(file, &fileInfo) != 0) {
        perror("Error getting file information");
        return 1;
    }
    printf("Inode number: %ld\n", (long)fileInfo.st_ino);
    printf("Block size: %ld bytes\n", (long)fileInfo.st_blksize);

    return 0;
}
