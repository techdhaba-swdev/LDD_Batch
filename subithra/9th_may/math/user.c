#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_PATH_ADD "/dev/addition_integer"
#define DEVICE_PATH_SUB "/dev/subtraction_integer"
#define DEVICE_PATH_MUL "/dev/multiplication_integer"
#define DEVICE_PATH_DIV "/dev/division_integer"

int main() {
    int fd_add, fd_sub, fd_mul, fd_div;
    int num1, num2, result;

    // Open the device files
    fd_add = open(DEVICE_PATH_ADD, O_RDWR);
    fd_sub = open(DEVICE_PATH_SUB, O_RDWR);
    fd_mul = open(DEVICE_PATH_MUL, O_RDWR);
    fd_div = open(DEVICE_PATH_DIV, O_RDWR);

    if (fd_add < 0 || fd_sub < 0 || fd_mul < 0 || fd_div < 0) {
        perror("Failed to open device file");
        return 1;
    }

    // Input values
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Perform addition
    write(fd_add, &num1, sizeof(int));
    write(fd_add, &num2, sizeof(int));
    read(fd_add, &result, sizeof(int));
    printf("Addition result: %d\n", result);

    // Perform subtraction
    write(fd_sub, &num1, sizeof(int));
    write(fd_sub, &num2, sizeof(int));
    read(fd_sub, &result, sizeof(int));
    printf("Subtraction result: %d\n", result);

    // Perform multiplication
    write(fd_mul, &num1, sizeof(int));
    write(fd_mul, &num2, sizeof(int));
    read(fd_mul, &result, sizeof(int));
    printf("Multiplication result: %d\n", result);

    // Perform division
    write(fd_div, &num1, sizeof(int));
    write(fd_div, &num2, sizeof(int));
    read(fd_div, &result, sizeof(int));
    printf("Division result: %d\n", result);

    // Close the device files
    close(fd_add);
    close(fd_sub);
    close(fd_mul);
    close(fd_div);

    return 0;
}
