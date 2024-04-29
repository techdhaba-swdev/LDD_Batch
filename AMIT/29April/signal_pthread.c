#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include<unistd.h>
                                                // Signal handler for SIGUSR1
void handle_sigusr1(int signum)
{
    printf("Thread ID:%lu received SIGUSR1 Signal.\n", pthread_self());
}

// Thread function
void* thread_function(void* arg) 
{
   
                                     // set the signal handler for this thread
    signal(SIGUSR1, handle_sigusr1); 
   
    kill(getpid(),SIGUSR1);          //trigger the signal and call sigusr1   //kill -SIGUSR1 PID
   
    printf("its working\n");
  
    sleep(2);

    return NULL;
}

int main()
{    

    
    pthread_t thread1,thread2,thread3;

                                                             // Create multiple threads
   
        pthread_create(&thread1, NULL, thread_function, NULL);
        pthread_create(&thread2, NULL, thread_function, NULL);
        pthread_create(&thread3, NULL, thread_function, NULL);

        pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
        pthread_join(thread3, NULL);
 
      
    printf("All threads have completed.\n");
 

    return 0;
}
