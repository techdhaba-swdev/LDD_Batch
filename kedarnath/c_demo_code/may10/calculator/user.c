#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/calculator"

int main() {
    int fd;
    int input_value1, input_value2, output_value;
    char operation;

    printf("Enter the first integer value: ");
    scanf("%d", &input_value1);

    printf("Enter the second integer value: ");
    scanf("%d", &input_value2);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operation);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Write the input values and operator to the device
    write(fd, &input_value1, sizeof(int));
    write(fd, &input_value2, sizeof(int));
    write(fd, &operation, sizeof(char));

    // Read the result value from the device
    read(fd, &output_value, sizeof(int));

    printf("Result received from kernel: %d\n", output_value);

    // Close the device file
    close(fd);

    return 0;
}




