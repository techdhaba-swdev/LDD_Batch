#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<errno.h>
struct user_data {
    int value;
    char message[25];
};

#define DATA_SIZE sizeof(struct user_data)

int main() {
    int fd;
    struct user_data data;

    fd = open("/dev/datatransfer", O_RDONLY);
    if (fd < 0) {
        perror("Error opening device");
        return 1;
    }

    if (read(fd, &data, DATA_SIZE) != DATA_SIZE) {
         fprintf(stderr, "Error reading from device: %s\n", strerror(errno));
    close(fd);
    return 1;
}

    printf("Received data: value = %d, message = %s\n", data.value, data.message);

    close(fd);
    return 0;
}
