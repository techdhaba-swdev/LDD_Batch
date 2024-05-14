#include <stdio.h> // Include necessary headers
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define IOCTL_SET_MSG _IOW('q', 1, char *) // Define IOCTL command

int main() {
    int fd; // Declare file descriptor variable
    char message[100] = "New message for the driver"; // Declare and initialize message buffer

    fd = open("/dev/char_driver", O_RDWR); // Open device file for read and write
    if (fd < 0) { // Check if open operation failed
        perror("Failed to open the device"); // Print error message
        return -1; // Return error code
    }

    ioctl(fd, IOCTL_SET_MSG, message); // Send IOCTL command to device with message

    close(fd); // Close device file
    return 0; // Return success
}
