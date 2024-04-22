#include<pthread.h>
#include <stdio.h>
#include<stdlib.h>
#define MAX 20 //numbers to print
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER; //initialized mutex
pthread_cond_t cond=PTHREAD_COND_INITIALIZER; //initialized condition
int counter=0;
void *even()
{
   while(counter<MAX)
   {
       pthread_mutex_lock(&mutex); //locked for every element
       while(counter%2!=0)
       {
           pthread_cond_wait(&cond,&mutex); //signaled to wait if number is odd
       }
       printf("%d\n",counter); //even number printed
       counter++;
       pthread_cond_signal(&cond); //released the wait
       pthread_mutex_unlock(&mutex); //unlocked the mutex
   }
   
}
void *odd()
{
    while(counter<MAX)
    {
        pthread_mutex_lock(&mutex);
        while(counter%2==0)
        {
            pthread_cond_wait(&cond,&mutex);
        }
        printf("%d\n",counter); //odd numbers printed
        counter++;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL,&even,NULL);
    pthread_create(&t2,NULL,&odd,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;
}
