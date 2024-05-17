#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/arithmetic"

int main()
{
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Error opening device");
        return 1;
    }

    int a = 10, b = 5;
    long result;

    // Sum
    ioctl(fd, 'S', &a);
    ioctl(fd, 'S', &b);
    read(fd, &result, sizeof(long));
    printf("Sum: %ld\n", result);

    // Multiplication
    ioctl(fd, 'M', &a);
    ioctl(fd, 'M', &b);
    read(fd, &result, sizeof(long));
    printf("Multiplication: %ld\n", result);

    // Division
    ioctl(fd, 'D', &a);
    ioctl(fd, 'D', &b);
    read(fd, &result, sizeof(long));
    printf("Division: %ld\n", result);

    // Subtraction
    ioctl(fd, 'R', &a);
    ioctl(fd, 'R', &b);
    read(fd, &result, sizeof(long));
    printf("Subtraction: %ld\n", result);

    close(fd);
    return 0;
}
