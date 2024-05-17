#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>

#define DEVICE_PATH "/dev/reverse_dev"
#define REVERSE_STRING _IO('R', 1)

int main() {
    int fd;
    char input_string[100] = "hii manasa";
    
    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return errno;
    }
    
    // Get input string from user
    printf("Enter a string to reverse: ");
    fgets(input_string, sizeof(input_string), stdin);
    
    // Write the input string to the device
    write(fd, input_string, sizeof(input_string));
    
    // Use ioctl to trigger the string reversal
    ioctl(fd, REVERSE_STRING);
    
    // Read the reversed string from the device
    read(fd, input_string, sizeof(input_string));
    
    // Print the reversed string
    printf("Reversed string: %s\n", input_string);
    
    // Close the device file
    close(fd);
    
    return 0;
}
