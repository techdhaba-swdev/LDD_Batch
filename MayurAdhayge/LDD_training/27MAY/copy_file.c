#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main() {
    int source_fd = open("sample.txt", O_RDONLY);
    

    int dest_fd = open("output.txt", O_WRONLY | O_CREAT);
   

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    bytes_read = read(source_fd, buffer, sizeof(buffer));
    bytes_written = write(dest_fd, buffer, bytes_read);
       

    close(source_fd);
    close(dest_fd);
    printf("read data=%ld \t write data=%ld",bytes_read, bytes_written);
    printf("File copied successfully.\n");

    return 0;
}
