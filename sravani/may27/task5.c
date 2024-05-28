#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FILENAME "example.txt"

int main() {
    struct stat file_stat;

    // Get file status using lstat
    if (lstat(FILENAME, &file_stat) == -1) {
        perror("Failed to get file status");
        exit(EXIT_FAILURE);
    }

    // Check file type
    if (S_ISREG(file_stat.st_mode))
        printf("%s is a regular file.\n", FILENAME);
    else if (S_ISDIR(file_stat.st_mode))
        printf("%s is a directory.\n", FILENAME);
        else
        printf("%s is of unknown type.\n", FILENAME);

    return 0;
}
