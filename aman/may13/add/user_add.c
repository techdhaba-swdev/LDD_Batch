#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_NAME "/dev/add_number"
#define BUFFER_SIZE 1024

int main() {
    int file_descriptor;
    char buffer[BUFFER_SIZE];

    file_descriptor = open(DEVICE_NAME, O_RDWR);
    if (file_descriptor < 0) {
        printf("Failed to open the device\n");
        return -1;
    }

    printf("Enter two numbers separated by a space: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    write(file_descriptor, buffer, strlen(buffer));

    printf("Result from kernel: ");
    read(file_descriptor, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    close(file_descriptor);
    return 0;
}
