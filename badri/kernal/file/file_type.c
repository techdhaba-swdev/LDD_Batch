#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat file_info;

    // Call lstat system call to get file information
    if (lstat("badri.txt", &file_info) == -1) {
        perror("Failed to get file information");
        return 1;
    }

    // Check the type of file
    if (S_ISREG(file_info.st_mode)) {
        printf("badri.txt is a regular file\n");
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("badri.txt is a directory\n");
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("badri.txt is a symbolic link\n");
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("badri.txt is a FIFO/pipe\n");
    } else if (S_ISSOCK(file_info.st_mode)) {
        printf("badri.txt is a socket\n");
    } else if (S_ISCHR(file_info.st_mode)) {
        printf("badri.txt is a character device\n");
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("badri.txt is a block device\n");
    } else {
        printf("badri.txt is of unknown type\n");
    }

    return 0;
}
