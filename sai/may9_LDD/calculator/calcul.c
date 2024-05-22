#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH "/dev/calculator"

int main() {
    int fd;
    char operand[80];
    char result[80];
    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return -1;
    }

    // Prompt for input
    printf("Enter operand and operation (+, -, *, /) separated by space: ");
    scanf("%c",&operand);

    // Write input to device
    write(fd, operand, sizeof(operand));  

    // Read result from device
  
    read(fd, result, sizeof(result)); 
        

    // Print the result
    printf("Result: %s\n", result);

    // Close the device file
    close(fd);

    return 0;
}
