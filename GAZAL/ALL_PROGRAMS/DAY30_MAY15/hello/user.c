#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#define MY_CUSTOM_SYSCALL_NR 333
int main() {
    int arg1 = 10;
    char *arg2 = "Hello";
    long result = syscall(MY_CUSTOM_SYSCALL_NR, arg1, arg2);
    if (result < 0) {
        perror("syscall");
        return 1;
    }
return 0;
}
