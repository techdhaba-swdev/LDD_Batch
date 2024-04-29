#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

                                                              // Signal handler for SIGUSR1
void handle_sigusr1(int signum) 
{
    printf("Received custom signal (SIGUSR1). Hello !\n");
}

int main() {
                                               // set the signal handler for SIGUSR1
    signal(SIGUSR1, handle_sigusr1);
    
    printf("PID: %d\n",getpid());
    printf("Running. Press Ctrl+C to exit.\n");

    while (1) 
    {
        // nothing
         sleep(2);		 // Generate the custom signal (SIGUSR1)
        kill(getpid(), SIGUSR1);  //kill -SIGUSR1 PID
    }

    return 0;
}
