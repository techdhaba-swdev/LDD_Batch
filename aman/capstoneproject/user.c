#include <stdio.h>          // For standard input/output functions
#include <stdlib.h>         // For standard library functions, including EXIT_FAILURE and EXIT_SUCCESS
#include <fcntl.h>          // For file control options (open function)
#include <unistd.h>         // For close function
#include <sys/ioctl.h>      // For ioctl function
#include<string.h>
#define DEVICE_PATH "/dev/my_string_slicer_device" // Path to the string slicer device
#define IOCTL_MAGIC 'c'                            // Magic number for ioctl
#define IOCTL_SLICE _IOWR(IOCTL_MAGIC, 1, struct slice_data) // ioctl command definition

// Define a structure to hold the string slicing data
struct slice_data {
    char input[256];  // Input string
    char output[256]; // Output string containing first characters of each word
};

int main() {
    int fd; // File descriptor for the device
    struct slice_data data; // Structure to hold user input and result

    // Open the device for reading and writing
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) { // Check if the device failed to open
        perror("Failed to open the device"); // Print error message
        return EXIT_FAILURE; // Return failure status
    }

    // Prompt user for input and read the string
    printf("Enter a string: ");
    fgets(data.input, sizeof(data.input), stdin); // Read input string

    // Remove newline character if present
     size_t len = strlen(data.input);
    if (len > 0 && data.input[len - 1] == '\n') {
        data.input[len - 1] = '\0';
    }

    // Perform ioctl to send data to the kernel module and get the result
    if (ioctl(fd, IOCTL_SLICE, &data) < 0) { // Check if ioctl failed
        perror("Failed to execute ioctl"); // Print error message
        close(fd); // Close the device
        return EXIT_FAILURE; // Return failure status
    }

    // Print the result of the string slicing
    printf("Sliced output: %s\n", data.output);

    close(fd); // Close the device
    return EXIT_SUCCESS; // Return success status
}