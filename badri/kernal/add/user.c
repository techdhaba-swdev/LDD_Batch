#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/sum"

int main() {
    int fd;
    int num1, num2, sum;

    printf("Enter the first integer value: ");
    scanf("%d", &num1);
    
    printf("Enter the second integer value: ");
    scanf("%d", &num2);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Write the two input values to the device
    write(fd, &num1, sizeof(int));
    write(fd, &num2, sizeof(int));

    // Read the sum value from the device
    read(fd, &sum, sizeof(int));

    printf("Sum received from kernel: %d\n", sum);

    // Close the device file
    close(fd);

    return 0;
}
