#include <stdio.h>
#include <unistd.h> // for write system call
void _start()
{
const char msg[] = "Hello, world!\n";
write(1, msg, sizeof(msg)-1); //use write system call to point
_exit(0); // use _exit system call to exit
}

