#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include<pthread.h>
#include <errno.h>

#define DEVICE_PATH "/dev/calc_char_device"
#define BUFFER_SIZE 80

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}
void *add_thread(void *args) {
    int fd;
    char write_buffer[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];
    ssize_t bytes_written, bytes_read;

    // Open the device
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd == -1) {
        handle_error("Failed to open device");
    }

    // Example expression to send to the device
    strcpy(write_buffer, "12 + 34");

    // Write the expression to the device
    bytes_written = write(fd, write_buffer, strlen(write_buffer));
    if (bytes_written == -1) {
        handle_error("Failed to write to the device");
    }
      // Read the result from the device
    bytes_read = read(fd, read_buffer, BUFFER_SIZE - 1);
    if (bytes_read == -1) {
        handle_error("Failed to read from the device");
    }

    // Null-terminate the read buffer and print the result
    read_buffer[bytes_read] = '\0';
    printf("Result: %s\n", read_buffer);

    // Close the device
    if (close(fd) == -1) {
        handle_error("Failed to close the device");
    }
}

int main()
{
        pthread_t add_tid;
        if(pthread_create(&add_tid,NULL,&add_thread,NULL)){
                fprintf(stderr,"Error creating Add thread\n");
                return 1;
        }
        if(pthread_join(&add_tid,NULL)){
                fprintf(stderr,"Error joining add_thread");
                return 2;
        }
        return 0;
}

