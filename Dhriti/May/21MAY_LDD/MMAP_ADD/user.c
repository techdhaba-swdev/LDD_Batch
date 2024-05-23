#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
#define DEVICE_NAME "/dev/addition_device"

int main() {
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1); // Read first number from user input
    printf("Enter second number: ");
    scanf("%d", &num2); // Read second number from user input
    
    int fd = open(DEVICE_NAME, O_RDWR); // Open the character device
    if(fd < 0) {
        perror("Failed to open the device"); // Print error message if opening device fails
        return -1;
    }
    
    char buffer[50];
    sprintf(buffer, "%d+%d", num1, num2); // Format numbers as a string
    

    write(fd, buffer, sizeof(buffer)); // Write the string to the device
    

    memset(buffer,0,sizeof(buffer));
    read(fd, buffer, sizeof(buffer));

    printf("Sum: %s\n", buffer);
    close(fd); // Close the device
    return 0;
}
