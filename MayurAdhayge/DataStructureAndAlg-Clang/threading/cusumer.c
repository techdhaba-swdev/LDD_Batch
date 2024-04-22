#include<stdio.h>
#include<pthread.h>
#define Max_Size 5
pthread_mutex_t bufLock;
int count;
void *producer(char* buf)
{
	for(;;)
	{
	if(count==Max_Size)break;
	pthread_mutex_lock(&bufLock);
	buf[count]=getchar();
	count++;
	pthread_mutex_unlock(&bufLock);
}
putchar('\n');
}

void *consumer(char* buf)
{
	for(;;)
	{	
	if(count==-1)break;
	pthread_mutex_lock(&bufLock);
	putchar(buf[count]);
	count--;
	pthread_mutex_unlock(&bufLock);
	}
	putchar('\n');
}
int main()
{
char buffer[Max_Size];
pthread_t p1,p2;
count=0;

pthread_mutex_init(&bufLock,NULL);

pthread_create(&p1,NULL,(void*)producer,&buffer);
pthread_join(p1,NULL);

pthread_create(&p2,NULL,(void*)consumer,&buffer);
pthread_join(p2,NULL);

//consumer(&buffer);
pthread_mutex_destroy(&bufLock);
return 0;
}
