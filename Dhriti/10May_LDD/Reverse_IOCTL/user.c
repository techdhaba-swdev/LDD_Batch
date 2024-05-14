#include <stdio.h> 
#include <fcntl.h> // File control header file
#include <unistd.h> 
#include <sys/ioctl.h> // Input-output control header file
#include <string.h>
#define DEVICE_FILE "/dev/reverse" // Device file path

#define IOCTL_REVERSE_STRING _IOW('R', 1, char *) // IOCTL command to reverse a string

int main() {
    int fd; // Open the device file for read/write access
    fd = open("/dev/reverse", O_RDWR);
    if (fd < 0) { // Check if opening the device file failed
        perror("Failed to open the device."); // Print error message
        return -1; // Return with error code
    }

    char string[] = "Hello, world!"; // Define a string
    printf("Original string: %s\n", string); 

    ioctl(fd,IOCTL_REVERSE_STRING, string);

    printf("Reversed string: %s\n", string); 

    close(fd); 
    return 0; 

}


