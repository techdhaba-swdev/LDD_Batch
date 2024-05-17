
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("/dev/double_integer", O_RDWR);
    if (fd < 0) {
        perror("Error opening device");
        return 1;
    }

    int input_value;
    printf("Enter an integer: ");
    scanf("%d", &input_value);

    // Write the input value to the device
    write(fd, &input_value, sizeof(int));

    // Read the doubled value from the device
    int doubled_value;
    read(fd, &doubled_value, sizeof(int));
    printf("Doubled value: %d\n", doubled_value);

    close(fd);
    return 0;
}
