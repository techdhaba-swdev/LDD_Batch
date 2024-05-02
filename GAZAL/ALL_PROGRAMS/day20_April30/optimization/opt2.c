#include <stdio.h>
#include <time.h>

int main(){

clock_t start = clock();

int sum = 0;
for(int i = 1; i <= 1000; i++){
sum += i;
}
clock_t end = clock();

double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("sum of first 1000 numbers: %d\n",sum);
printf("time taken :%f seconds\n",time_taken);
return 0;
}

