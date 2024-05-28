#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(){
	const char *source="source.txt";
	const char *destiny="destiny.txt";
	int fd_source,fd_destiny;
        ssize_t bytes_written, bytes_read;
        char buffer[BUFFER_SIZE];

	fd_source=open(source,O_RDONLY);
	if(fd_source == -1){
		perror("Failed to open file for reading");
        exit(EXIT_FAILURE);
    }
	fd_destiny=open(destiny, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd_destiny == -1) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }
// Copy data from source file to destination file
    while ((bytes_read = read(fd_source, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_destiny, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Write error");
            close(fd_source);
            close(fd_destiny);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Read error");
        close(fd_source);
        close(fd_destiny);
        exit(EXIT_FAILURE);
    }

    // Close both files
    if (close(fd_source) == -1 || close(fd_destiny) == -1) {
        perror("Failed to close files");
        exit(EXIT_FAILURE);
    }

    printf("File copied successfully.\n");
    return 0;
}

