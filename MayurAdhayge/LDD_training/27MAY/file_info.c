#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    struct stat file_info;

   
    fd = open("sample.txt", O_RDONLY);
    

    
    if (fstat(fd, &file_info) == -1) {
        perror("Error getting file information");
        close(fd);
        return 1;
    }

  
    printf("File inode number: %ld\n", (long)file_info.st_ino);
    printf("File size: %ld bytes\n", (long)file_info.st_size);
    printf("File mode: %o\n", file_info.st_mode);

 
    close(fd);

    return 0;
}
