#include <stdio.h>
#include<time.h>
int main() {
    clock_t start = clock(); //start the clock
    int i;
    int sum = 0;

for (i = 0; i <= 10; i++) 
    {
        sum += i;
    }

 clock_t end = clock(); //stop the clock

 double time_taken = ((double)(end - start)); //cal the elapsed time'

 printf("The sum is: %d\n", sum);

   printf("Time taken: %f seconds \n",time_taken);
 return 0;
}

