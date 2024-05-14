#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define DEVICE_PATH "/dev/sum_node"
int main() {
    int fd;
    int input_value1,  input_value2, output_value;
    printf("Enter an integer value1 : ");
    scanf("%d", &input_value1);
    printf("Enter an integer value2 : ");
    scanf("%d", &input_value2);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }
    // Write the input value to the device
    write(fd, &input_value1, sizeof(int));
    write(fd, &input_value2, sizeof(int));
    // Read the doubled value from the device
    read(fd, &output_value, sizeof(int));
    printf("Doubled value received from kernel: %d\n", output_value);
    // Close the device file
    close(fd);
    return 0;
}
