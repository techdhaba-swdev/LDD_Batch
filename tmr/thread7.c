#include <stdio.h>
#include<string.h>
#include <pthread.h>

#define MAX_SIZE 5

   pthread_mutex_t bufLock;

   int count;

   void producer(char* buf)
{

   for(;;)
   {

     while(count== Max);

     pthread_mutex_lock(&bufLock);

     buf[count] = getChar();

     count++;

     pthread_mutex_unlock(&buflock);
   }
}

void consumer(char* buf)
{


   for(;;)
    { 

        while(count== 0);

        pthread_mutex_lock(&bufLock);

        putChar(buf[count-1]);

        count--;

        pthread_mutex_unlock(&bufLock);
    }
}

int main() 

{


    char buffer[Max];

    pthread_t t1;

    int count;

    pthread_mutex_init(&bufLock,NULL);

    pthread_create(&t1, NULL, (void*)producer, &buffer);

    consume(&buffer);

    return 0;
}



