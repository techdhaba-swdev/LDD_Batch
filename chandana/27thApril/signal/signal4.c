#include <stdio.h>
#include <signal.h>
 
// Function to handle any signal (demonstration purposes)
void signal_handler(int sig) {
    printf("Caught signal: %d\n", sig);
 
    // *Important:* Cannot perform actions that rely on external resources
    // due to asynchronous nature of signals. (e.g., printf, network I/O)
 
    // Example of safe action: setting a flag to indicate signal received
    static int signal_received = 0;
    signal_received = 1;
}
 
int main() {
 
    // Attempt to register signal handler for SIGKILL (will fail)
    if (signal(SIGKILL, signal_handler) == SIG_ERR) {
        perror("signal");
        return 1;
    }
 
    printf("Process running...\n");
 
    // Loop to demonstrate program execution
    while (1) {
        // Simulate work being done (replace with actual work)
        sleep(1);
 
        // Check if signal was received (safe action)
        if (/* signal_received flag */) {
            printf("Signal received (likely not SIGKILL due to limitations).\n");
            break;
        }
    }
 
    printf("Exiting program.\n");
    return 0;
}
