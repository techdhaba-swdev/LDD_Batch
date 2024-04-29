#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int signum) {
    printf("Custom signal (SIGUSR1) received.\n");
}

int main() {
   
    signal(SIGUSR1, sigusr1_handler);

    printf("Generating custom signal every 2 seconds.\n");
   
    while (1) {
        kill(getpid(), SIGUSR1);
        sleep(2);
    
    }

    return 0;
}
