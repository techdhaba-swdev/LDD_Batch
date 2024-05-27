#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
int main() {
    char file_path[256]; 
    struct stat file_stat;

    printf("Enter the file path: ");
    if (fgets(file_path, sizeof(file_path), stdin) == NULL) {
        perror("Error reading file path");
        return 1;
    }

    file_path[strcspn(file_path, "\n")] = '\0';

    if (stat(file_path, &file_stat) == -1) {
        perror("Error getting file information");
        return 1;
    }

    
    if (S_ISREG(file_stat.st_mode)) {
        printf("File: %s\nType of file:file\n", file_path);
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("File: %s\nType of file: Directory\n", file_path);
    } else {
        printf("File: %s\nType of file: Unknown\n", file_path);
    }

    return 0;
}

