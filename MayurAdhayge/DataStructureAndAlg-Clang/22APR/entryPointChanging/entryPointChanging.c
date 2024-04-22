#include <stdio.h>
#include <unistd.h>
// Define the custom _start function as the entry point
void _start() {
    const char msg[]="heloo worldddd..\n";
    write(1,msg,sizeof(msg));
    _exit(0);
}
