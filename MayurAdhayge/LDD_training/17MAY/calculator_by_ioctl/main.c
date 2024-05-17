#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_PATH "/dev/ioctl_calculator_device"

#define IOCTL_CMD_ADD _IOWR('+', 1, struct calculation_info)
#define IOCTL_CMD_MINUS _IOWR('-', 2, struct calculation_info)
#define IOCTL_CMD_MUL _IOWR('*', 3, struct calculation_info)
#define IOCTL_CMD_DIV _IOWR('/', 4, struct calculation_info)
struct calculation_info
{
int value1;
int value2;
char ops;
float result;
};

int main() {
    int fd;
    
    struct calculation_info info;
    int value = 42;

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }
    
    printf("ente the vaules for the integer opration\n");
    printf("\nenter the value for the calculation:-");
    scanf("%d",&info.value1);
    printf("\nenter the value for the calculation:-");
        scanf("%d",&info.value2);
    printf("\nenter which opration you have to perform in calculator (for:- +,-,*,/):-");
        scanf("%c",&info.ops);


switch(info.ops){
case '+':
if (ioctl(fd, IOCTL_CMD_ADD, &info) < 0) {
        perror("Failed to execute ioctl");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("IOCTL command sent with result of %d %c %d= %d\n", info.value1,info.value2,info.ops,info.result);
    break;
    
case '-':
if (ioctl(fd, IOCTL_CMD_MINUS, &info) < 0) {
        perror("Failed to execute ioctl");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("IOCTL command sent with result of %d %c %d= %d\n", info.value1,info.value2,info.ops,info.result);
    break;
case '*':
if (ioctl(fd, IOCTL_CMD_MUL, &info) < 0) {
        perror("Failed to execute ioctl");
        close(fd);
        return EXIT_FAILURE;
    }

   printf("IOCTL command sent with result of %d %c %d= %d\n", info.value1,info.value2,info.ops,info.result);
    break;
case '/':
if (ioctl(fd, IOCTL_CMD_DIV, &info) < 0) {
        perror("Failed to execute ioctl");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("IOCTL command sent with result of %d %c %d= %d\n", info.value1,info.value2,info.ops,info.result);
    break;
  default:
       close(fd);
       return EXIT_FAILURE;
    
 }
    

    close(fd);
    return EXIT_SUCCESS;
}
