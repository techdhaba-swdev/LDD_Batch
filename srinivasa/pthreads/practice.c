#include<stdio.h>
#include<pthread.h>
void *printmsg(void);

int main()
{
	pthread_t thread1,thread2;
	int a, b ;
	a = pthread_create(&thread1, NULL, printmsg, NULL);
	b = pthread_create(&thread2, NULL, printmsg, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("thraed1 returns :%d",a);
	return 0;

}
void *printmsg(void )
{
	printf("printing from thread ");
}
