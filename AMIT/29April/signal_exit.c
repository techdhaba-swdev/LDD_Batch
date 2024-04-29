#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

                                                      // Signal handler for SIGINT (Ctrl+C)
void handle_sigint(int signum)
{
    printf("\nReceived SIGINT (Ctrl+C). Exiting gracefully.\n");
    exit(EXIT_SUCCESS);
}

int main() {
                                        
    signal(SIGINT, handle_sigint);

    printf("Running. Press Ctrl+C to exit.\n");

    while (1) {
        
        //nothing
    }

    return EXIT_SUCCESS;
}
