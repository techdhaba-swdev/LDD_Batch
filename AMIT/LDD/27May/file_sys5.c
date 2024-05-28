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

    // Check file type
    if (S_ISREG(file_info.st_mode)) {
        printf("%s is a regular file.\n", filename);
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("%s is a directory.\n", filename);
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("%s is a symbolic link.\n", filename);
    } else if (S_ISCHR(file_info.st_mode)) {
        printf("%s is a character special file (device).\n", filename);
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("%s is a block special file (device).\n", filename);
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("%s is a named pipe (FIFO).\n", filename);
    } else if (S_ISSOCK(file_info.st_mode)) {
        printf("%s is a socket.\n", filename);
    } else {
        printf("%s has an unknown file type.\n", filename);
    }

    return 0;
}

