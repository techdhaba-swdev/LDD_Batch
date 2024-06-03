#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define USB_DEVICE_NODE "/dev/usb_driver"

int main() {
    int fd;
    char write_buf[512];
    char read_buf[512];
    int bytes_written, bytes_read;

    // Open the USB device file
    fd = open(USB_DEVICE_NODE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device node");
        return -1;
    }

    // Write data to the USB device
    printf("Enter data to write to USB device: ");
    fgets(write_buf, sizeof(write_buf), stdin);
    bytes_written = write(fd, write_buf, sizeof(write_buf));
    if (bytes_written < 0) {
        perror("Failed to write to USB device");
        close(fd);
        return -1;
    }

    // Read data from the USB device
    bytes_read = read(fd, read_buf, sizeof(read_buf));
    if (bytes_read < 0) {
        perror("Failed to read from USB device");
        close(fd);
        return -1;
    }

    // Print the read data
    printf("Data read from USB device: %s\n", read_buf);

    // Close the USB device file
    close(fd);

    return 0;
}


