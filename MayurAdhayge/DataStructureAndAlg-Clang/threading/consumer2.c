#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutex_t m1;
int count;
int main()
{
pthread_t t1;
pthread_mutex_init(&m1,NULL);
pthread_create(&t1,NULL,,);
pthread_join(t1,NULL);
pthread_mutex_destroy(m1);

}
