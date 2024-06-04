#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define DEVICE_NAME "/dev/timer_device"

void load_module() {
    system("insmod timer_module.ko");
}

void unload_module() {
    system("rmmod timer_module");
}

int main() {
    int fd;

    load_module();

    fd = open(DEVICE_NAME, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open the device");
        unload_module();
        return errno;
    }

    printf("Device opened successfully\n");

    // Interact with the device if needed
    // ...

    close(fd);
    unload_module();
    printf("Device closed and module unloaded\n");

    return 0;
}

