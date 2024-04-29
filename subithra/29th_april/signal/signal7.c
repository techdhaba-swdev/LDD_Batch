#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


struct SignalHandlers {
    void (*handler1)(int);
    void (*handler2)(int);
};


void signal_handler_1(int signum) {
    printf("Signal %d received (Handler 1).\n", signum);
    exit(signum); 
}

// Signal handler function 2
void signal_handler_2(int signum) {
    printf("Signal %d received (Handler 2).\n", signum);
    exit(signum); 
}

int main() {
   
    struct SignalHandlers handlers = {signal_handler_1, signal_handler_2};
    struct sigaction sa1,sa2;
    sa1.sa_flags = 0;
      sa2.sa_flags = 0;
    sigemptyset(&sa1.sa_mask);
    sigemptyset(&sa2.sa_mask);
    
    sa1.sa_handler = handlers.handler1;
    if(sigaction(SIGINT,&sa1,NULL)==-1){
    perror("sigaction");
    exit(EXIT_FAILURE);
    }
     sa2.sa_handler = handlers.handler2;
    if(sigaction(SIGINT,&sa2,NULL)==-1){
    perror("sigaction");
    exit(EXIT_FAILURE);
    }
    
    printf("Waiting for SIGINT...\n");
    while (1) {
        
    }

    return 0;
}
