#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

#define DEVICE_NAME "/dev/reverse_string" 
#define IOCTL_REVERSE_STRING _IOWR('q', 1, char *)
#define MAX_LENGTH 100

int main() {
    int fd;
    char input_string[MAX_LENGTH];
    char reversed_string[MAX_LENGTH];

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device file");
        return 1;
    }

    // Get input string from user
    printf("Enter a string to reverse: ");
    fgets(input_string, MAX_LENGTH, stdin); 
    //input_string[strcspn(input_string, "\n")] = '\0'; // Remove trailing newline

    // Send IOCTL command to kernel module to reverse the string
    //ioctl(fd, IOCTL_REVERSE_STRING, input_string);
    ioctl(fd, IOCTL_REVERSE_STRING, input_string);

    printf("Reversed string received from device: %s\n", input_string);



    // Read the reversed string from the device
    //read(fd, reversed_string, MAX_LENGTH); 

    //printf("Reversed string received from device: %s\n", reversed_string);

    // Close the device file
    close(fd);

    return 0;
}




