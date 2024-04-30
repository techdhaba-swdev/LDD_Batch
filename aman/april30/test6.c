#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<time.h>
void signal_handler(int sig){
        if (sig == SIGINT){
                printf("Caught SIGINT: Interrupt signal\n");
		exit(0);
	}
}
int main(){
	signal(SIGINT, signal_handler);
	int sum;
	clock_t start = clock();
	int i;
	for(i=0;i<10000;i++){
		sum += i;
	}
	clock_t stop = clock();
	double time_taken = ((double)(stop-start));
	printf("Sum: %d\n", sum);
	printf("time taken: %f\n", time_taken);
	return 0;
}
