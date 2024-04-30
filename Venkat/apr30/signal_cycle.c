#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void sigusr1_handler(int signum) {
    printf("Caught SIGUSR1 signal\n");
}

int main() {
    // Register SIGUSR1 handler
    signal(SIGUSR1, sigusr1_handler);

    // Get the process ID
    printf("Process ID: %d\n", getpid());

    printf("Generated a custom signal\n");

    // Start the clock
    clock_t start = clock();

    while (1) {
        printf("Waiting for the signal\n");
        sleep(2);

        printf("Generating the custom signal SIGUSR1\n");
        kill(getpid(), SIGUSR1); // sending SIGUSR1 signal to the current process using kill() this triggers Register SIGUSR1 handler
				 //Generate the custom signal kill send send SIGUSR to a process at process ID SIGUSR like invoksignal
				 
        // Stop the clock
        clock_t end = clock();

        // Calculate the elapsed time
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Time taken: %f seconds\n", time_taken);
    }
    return 0;

}
