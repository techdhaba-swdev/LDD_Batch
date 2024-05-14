#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NAME "/dev/calculator_dev"

int main() {
    int fd;
    char operation;
    int operand1, operand2;
    char buffer[100];
    int nbytes;

    
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device file");
        return 1;
    }

    
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);
    printf("Enter operand 1: ");
    scanf("%d", &operand1);
    printf("Enter operand 2: ");
    scanf("%d", &operand2);

  
    sprintf(buffer, "%c %d %d", operation, operand1, operand2);
    nbytes = write(fd, buffer, strlen(buffer));
    if (nbytes < 0) {
        perror("Failed to write to device");
        close(fd);
        return 1;
    }

    
    printf("Result: ");
    nbytes = read(fd, buffer, sizeof(buffer));
    if (nbytes < 0) {
        perror("Failed to read from device");
        close(fd);
        return 1;
    }

    
    printf("%s", buffer);

 
    close(fd);

    return 0;
}
