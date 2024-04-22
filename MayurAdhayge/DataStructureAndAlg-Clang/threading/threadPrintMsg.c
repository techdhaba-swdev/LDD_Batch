#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *printMSG(char* str1);
void *printMSG(char* str1)
{
	int* status=(int*) malloc(sizeof(int));
	printf("%s\n",str1);
	pthread_exit((void*) status);

}
void main (int argc ,char** argv[])
{
int *status= (int *) malloc(sizeof(int));
void *st;
char*s =(char *) malloc(sizeof(char)*10);
pthread_t thread1;
printf ("enter your msg:-");
scanf("%s",s);
printf("%s",s);
printf("thread is creating here \n");
pthread_create(&thread1,NULL,(void*)printMSG,s);
printf("thread is created:- %ld\n",thread1);
	pthread_join(thread1,&st);
	status=(int*) st;
printf("thead %ld is exit with %d code\n",thread1,*status);


}
