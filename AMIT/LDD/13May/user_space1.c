#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("/dev/double_integer", O_WRONLY);
    if (fd < 0) {
        perror("Error opening device");
        return 1;
    }

    int input_value = 10; // Change this value as needed
    write(fd, &input_value, sizeof(int));

    close(fd);
    return 0;
}
