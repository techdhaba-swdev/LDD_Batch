#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int signum) {
    printf("Received SIGUSR1 signal\n");
}

int main() {
    signal(SIGUSR1, sigusr1_handler);
    while (1) {
        printf("Waiting for SIGUSR1 signal...\n");
	kill(getpid(), SIGUSR1);
        sleep(3); // Wait for 3 seconds
    }
    return 0;
}
