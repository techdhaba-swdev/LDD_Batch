#include<stdio.h>
#include<time.h>
int main(){
	clock_t start = clock();
        int sum = 0;
        /*for(int i=1; i<=10000000;i++){
                sum += i;
        }*/
	clock_t end = clock();
	double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
        for(int i =0;i<=10000000;i += 2){
                sum += i;
                if(i+1< 10000000){
                        sum += i+1;
                }
        }
        printf("Sum of first 10000000 nymbers: %d\n", sum);
	printf("Time taken: %f seconds\n", time_taken);
        return 0;
}

