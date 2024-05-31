#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE "/dev/string_device"

int main()
{
    int fd;
    char input_string[256];
    char received_string[256];

    // Open the device
    fd = open(DEVICE, O_RDWR);
    if (fd < 0) {
        printf("Failed to open the device.\n");
        return -1;
    }

    printf("Enter a string: ");
    scanf("%[^\n]", input_string);

    // Write the string to the device
    write(fd, input_string, strlen(input_string));

    // Read the string back from the device
    read(fd, received_string, sizeof(received_string));

    printf("String received from kernel: %s\n", received_string);

    // Close the device
    close(fd);

    return 0;
}
