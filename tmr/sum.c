#include <stdio.h>
#include<time.h> 
int main() {

	clock_t start = clock();
    int i;

    int sum = 0;
 
    for (i = 1; i <= 100; i++) {

        sum += i;

    }

    clock_t end = clock();

    double time_taken = ((double)(end - start));

 
    printf("The sum is: %d\n", sum);
    printf("time taken:%f seconds\n",time_taken);
 
    return 0;

}
