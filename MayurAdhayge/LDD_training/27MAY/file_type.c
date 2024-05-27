#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    struct stat file_info;

    
    fd = open("sample.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    
    if (fstat(fd, &file_info) == -1) {
        perror("Error getting file information");
        close(fd);
        return 1;
    }

    
    if (S_ISREG(file_info.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("Directory\n");
    } else if (S_ISCHR(file_info.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("FIFO/pipe\n");
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISSOCK(file_info.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }

   
    close(fd);

    return 0;
}
