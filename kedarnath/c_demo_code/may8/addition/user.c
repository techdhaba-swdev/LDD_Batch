#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/addition"

int main() {
    int fd;
    int input_value1, input_value2, output_value;

    printf("Enter first integer value: ");
    scanf("%d", &input_value1);

    printf("Enter second integer value: ");
    scanf("%d", &input_value2);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Write the input values to the device
    write(fd, &input_value1, sizeof(int));
    write(fd, &input_value2, sizeof(int));

    // Read the sum value from the device
    read(fd, &output_value, sizeof(int));

    printf("Sum of the two values received from kernel: %d\n", output_value);

    // Close the device file
    close(fd);

    return 0;
}




