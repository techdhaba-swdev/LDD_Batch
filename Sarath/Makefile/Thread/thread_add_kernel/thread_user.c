#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#define THREADS 2
#define DEVICE_PATH "/dev/thread_add_sub"

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void *add_sub(void *arg){
	
	int fd,num1,num2,result;
        printf("Enter first number:");
        scanf("%d",&num1);
        printf("Enter second number:");
        scanf("%d",&num2);
        fd=open(DEVICE_PATH,O_RDWR);
        if(fd<0){
        perror("Failed to open the device file");
        return 1;
        }
        int buffer[2] = {num1, num2};
	write(fd, buffer, 2 * sizeof(int));  // Writing both values to the device

        read(fd, &result, sizeof(int));   // Reading the result from the device

        printf("Addition Result value received from kernel: %d\n", result);

        close(fd);
	return NULL;
}

int main()
{
	int ret;
	pthread_t thread[THREADS];
	ret=pthread_create(&thread[0],NULL,add_sub,NULL);
	if(ret!=0){
		perror("pthread_create(add)");
		exit(1);
	}
	/*ret=pthread_create(&thread[1],NULL,sub,NULL);
        if(ret!=0){
                perror("pthread_create(sub)");
                exit(1);
        }*/
	pthread_join(thread[0],NULL);
	//pthread_join(thread[1],NULL);
    	return 0;
}

	

