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

    int input_value = 5; // Change this value as needed
    write(fd, &input_value, sizeof(int));

    close(fd);

    // Now read the doubled value
    fd = open("/dev/double_integer", O_RDONLY);
    if (fd < 0) {
        perror("Error opening device");
        return 1;
    }

    int doubled_value;
    read(fd, &doubled_value, sizeof(int));
    printf("Doubled value: %d\n", doubled_value);

    close(fd);
    return 0;
}
