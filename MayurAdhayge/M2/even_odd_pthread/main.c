#include<stdio.h>
#include<pthread.h>



FILE *sample_fd;
FILE *even_fd;
FILE *odd_fd;
char line[100];

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

int i=1;


void *parsing(void *arg);


void *parsing_even(void *arg)
{
pthread_mutex_lock(&mutex);
sample_fd=fopen("sample.txt","r");
even_fd=fopen("even.txt","a");
odd_fd=fopen("odd.txt","a");
	
	while(fgets(line,sizeof(line),sample_fd)!=NULL)
	{
		printf("%s",line);
	  if (i%2==0)
	  {
	    fprintf(even_fd,"%s",line);
	  }
	  else
	  {
	    fprintf(odd_fd,"%s",line);
	  }
	  i++;
	}
	i=1;
	fclose(sample_fd);
fclose(even_fd);
fclose(odd_fd);
	pthread_mutex_unlock(&mutex);
return NULL;
}

int main()
{

pthread_t thread1,thread2,print_even_thread,print_odd_thread;


pthread_create(&thread1,NULL,parsing,NULL);
pthread_create(&thread2,NULL,parsing,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);


return 0;
}
