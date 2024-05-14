#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
#define DEVICE_PATH "/dev/calculator"

int main() {
    int fd;
    int value1, value2, result;
    char cal;
    printf("Enter two values to caliculate: ");
    scanf("%d %d", &value1, &value2);
    printf("enter ' + or - or * or  / ' to perfrom any operartion");
    scanf("%c",&cal);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Prepare the buffer to hold both values
    char  buffer[10];
    sprintf(buffer, "%d %d %c",value1, value2, cal);

    // Write both values to the device
    write(fd, buffer, strlen(buffer));

    // Read the result from the device
    read(fd, &result, sizeof(int));

    printf("Result value received from kernel: %d\n", result);

    // Close the device file
    close(fd);

    return 0;
}
