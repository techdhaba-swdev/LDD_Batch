#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void sigint_handler(int signum) {
    printf("\nCtrl+C pressed.exit program");
}
int main(){
	// Register the signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, sigint_handler);
      printf("exiting from code");
      // Loop indefinitely
    while (1) {
        // Do something or simply wait for signals
    }

    return 0;
}

