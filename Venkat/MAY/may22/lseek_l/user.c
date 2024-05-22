#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd_read = open(argv[1], O_RDONLY);
    if (fd_read == -1) {
        perror("open");
        return 1;
    }

    // Open the output file for writing
    int fd_write = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_write == -1) {
        perror("open");
        close(fd_read);
        return 1;
    }

    char buffer[1];
    ssize_t bytesRead;
    int count = 0;

    while ((bytesRead = read(fd_read, buffer, sizeof(buffer))) > 0) {
        if (count % 2 == 0) {
            // Write the alternate bytes to the output file
            write(fd_write, buffer, 1);
        }
        count++;
    }

    close(fd_read);
    close(fd_write);

    printf("Alternate bytes copied to output.txt\n");

    return 0;
}
