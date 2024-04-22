#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include<stdbool.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];            
int count = 0;                      
int in = 0;                         
int out = 0;                        

pthread_mutex_t mutex;              
pthread_cond_t buffer_not_full;    
pthread_cond_t buffer_not_empty;   
bool terminate = false;

int produce_item() {
    return rand() % 100;  
}

void insert_item(int item) {
    buffer[in] = item;      
    in = (in + 1) % BUFFER_SIZE;  
    count++;                
    printf("Produced item: %d\n", item);  
}

int remove_item() {
    int item = buffer[out];   
    out = (out + 1) % BUFFER_SIZE;  
    count--;                
    return item;            
}

void *producer(void *arg) {
    while (1) {
        int item = produce_item();    
        pthread_mutex_lock(&mutex);  

        while (count == BUFFER_SIZE)  
            pthread_cond_wait(&buffer_not_full, &mutex);

        insert_item(item);            

        pthread_cond_signal(&buffer_not_empty);  
        pthread_mutex_unlock(&mutex);            
      if(terminate){
	      pthread_exit(NULL);
       }
    }
}

void *consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);  

        while (count == 0)           
            pthread_cond_wait(&buffer_not_empty, &mutex);

        int item = remove_item();    

        pthread_cond_signal(&buffer_not_full);   
        pthread_mutex_unlock(&mutex);            

        printf("Consumed item: %d\n", item);
   if(terminate){
               pthread_exit(NULL);
       }

    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&buffer_not_full, NULL);
    pthread_cond_init(&buffer_not_empty, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

   sleep(1);
   
    terminate=true;

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&buffer_not_full);
    pthread_cond_destroy(&buffer_not_empty);

    return 0;
}
