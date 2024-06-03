#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define USB_DEVICE_PATH "/dev/usb_example"

int main() {
    int fd;
    char write_buffer[512];
    char read_buffer[512];
    int bytes_written, bytes_read;

    // Open the USB device file
    fd = open(USB_DEVICE_PATH, O_RDWR);
    if (fd == -1) {
        perror("Failed to open the device file");
        return EXIT_FAILURE;
    }

    // Write data to the USB device
    bytes_written = write(fd, "Hello from userspace!", sizeof("Hello from userspace!"));
    if (bytes_written == -1) {
        perror("Failed to write to the device");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Bytes written: %d\n", bytes_written);

    // Read data from the USB device
    bytes_read = read(fd, read_buffer, sizeof(read_buffer));
    if (bytes_read == -1) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Bytes read: %d\n", bytes_read);
    printf("Data read from device: %s\n", read_buffer);

    // Close the device file
    close(fd);

    return EXIT_SUCCESS;
}
	

