#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

void *thread_function(void *arg) {
    while(1) {
        printf("Thread running\n");
        sleep(1);
    }
    return NULL;
}

void signal_handler(int signal) {
    if (signal == SIGINT) {  // defalut interepting signal
        printf("Received SIGINT,Exiting\n");

    } else if (signal == SIGTSTP) {  // defalut suspending signal
        printf("Received SIGTSTP,Suspending\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    pthread_t thread_id; // phread_id its variable which stores unique id or 

    if (pthread_create(&thread_id, NULL, thread_function, NULL) != 0) { // every time i call this function
									// thread_id we are geneation identification which stores in thead_id
									//NULl it is flag attribute set to defalut
									//thread_function refer to function
									//NULL passing input to thead funtion
        perror("pthread_create"); // print the error
        exit(EXIT_FAILURE);
    }
     // actually it will  send signal to process SIGNIT to function          
    signal(SIGINT, signal_handler); // if i press ctrl + c it invokes SIGINT itself send as an agument to single_handler function
				    // as a signal the signal checks SIGINT it will 
    signal(SIGTSTP, signal_handler);

    while (1) {
        printf("Main thread running...\n");
        sleep(2);
    }

    return 0;
}

