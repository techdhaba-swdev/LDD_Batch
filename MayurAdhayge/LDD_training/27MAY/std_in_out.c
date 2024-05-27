#include <unistd.h>
#include <string.h>
int main() {
    char buffer [10];
    write(1, "enter your name:-", 17);
    read(1,buffer,10);
    write(1, buffer, 10);
    return 0;
}
