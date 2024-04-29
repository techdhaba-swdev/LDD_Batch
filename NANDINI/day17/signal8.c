#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int signum) {
    printf("Custom signal SIGUSR1 received.\n");
}

int main() {
    // Install sigusr1_handler as the handler for SIGUSR1
    signal(SIGUSR1, sigusr1_handler);

    printf("Custom signal SIGUSR1 will be periodically generated.\n");

    // Periodically generate SIGUSR1 every 3 seconds
    while (1) {
        printf("Generating SIGUSR1...\n");
        kill(getpid(), SIGUSR1); // Generate SIGUSR1 for the current process
        sleep(3); // Wait for 3 seconds before generating the signal again
    }

    return 0;
}
