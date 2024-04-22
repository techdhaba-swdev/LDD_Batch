#include <stdio.h>
#include<pthread.h>

#define MAX_NUM 20

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int count =1;

void* printEven(void* arg){
	while(count <= MAX_NUM){
		pthread_mutex_lock(&mutex);
		if(count %2==0) {
			printf("Even : %d\n",count);
			count++;
			pthread_cond_signal(&cond);
		}
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}
void* printOdd(void* arg){
        while(count <= MAX_NUM){
                pthread_mutex_lock(&mutex);
                if(count %2!=0) {
                        printf("Odd : %d\n",count);
                        count++;
                        pthread_cond_signal(&cond);
                }
                pthread_mutex_unlock(&mutex);
        }
        return NULL;
}

int main() {
	pthread_t tid1,tid2;

	pthread_create(&tid1,NULL,printEven,NULL);
	pthread_create(&tid2,NULL,printOdd,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	return 0;
}

