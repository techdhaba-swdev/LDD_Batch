#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

#define DEVICE_FILE "/dev/calcdev"
#define CALC_IO_MAGIC 'k'
#define CALC_ADD _IOWR(CALC_IO_MAGIC, 1, struct calc_data)
#define CALC_SUB _IOWR(CALC_IO_MAGIC, 2, struct calc_data)
#define CALC_MUL _IOWR(CALC_IO_MAGIC, 3, struct calc_data)
#define CALC_DIV _IOWR(CALC_IO_MAGIC, 4, struct calc_data)

struct calc_data {
    int operand1;
    int operand2;
    int result;
};

void perform_calculation(int fd, int op_code, struct calc_data *data) {
    if (ioctl(fd, op_code, data) == -1) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }
    printf("Result: %d\n", data->result);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <operand1> <operand2> <operation>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int operand1 = atoi(argv[1]);
    int operand2 = atoi(argv[2]);
    char *operation = argv[3];

    struct calc_data data;
    data.operand1 = operand1;
    data.operand2 = operand2;

    int fd = open(DEVICE_FILE, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (strcmp(operation, "add") == 0) {
        perform_calculation(fd, CALC_ADD, &data);
    } else if (strcmp(operation, "sub") == 0) {
        perform_calculation(fd, CALC_SUB, &data);
    } else if (strcmp(operation, "mul") == 0) {
        perform_calculation(fd, CALC_MUL, &data);
    } else if (strcmp(operation, "div") == 0) {
        if (operand2 == 0) {
            fprintf(stderr, "Error: Division by zero\n");
            close(fd);
            exit(EXIT_FAILURE);
        }
        perform_calculation(fd, CALC_DIV, &data);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", operation);
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
    return 0;
}
