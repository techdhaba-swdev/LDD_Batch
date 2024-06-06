#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

 

// Signal handler function for SIGUSR1
void sigusr1_handler(int signum) {
    printf("Received SIGUSR1 signal\n");
    // Custom handling for SIGUSR1
}

 

// Signal handler function for SIGUSR2
void sigusr2_handler(int signum) {
    printf("Received SIGUSR2 signal\n");
    // Custom handling for SIGUSR2
}

 

int main() {
    // Register signal handler for SIGUSR1
    signal(SIGUSR1, sigusr1_handler);

 

    // Register signal handler for SIGUSR2
    signal(SIGUSR2, sigusr2_handler);

 

    printf("PID: %d\n", getpid()); //used toobtain the process id of the current process
    printf("Send SIGUSR1 or SIGUSR2 to this process to trigger signal handlers\n");

 

    // Loop indefinitely
    while (5) {
        printf("Program is running\n");
        sleep(1); // Sleep for 1 second to prevent CPU usage
    }

 

    return 0;
}
