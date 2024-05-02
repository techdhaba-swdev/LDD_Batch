#include<stdio.h>
#include<time.h>

int main()
{
     int sum = 0;
     int n = 1000;
     clock_t start = clock();
#if 1 
     //original loop (less efficient)
     for(int i= 0 ; i< n;i++){
	     sum += i;
     }
 #else 
     //unrolled loop(improves perfermance for small loop iteration)
     for (int i = 0; i< n;i+=2)
     {
	     sum += i;
	     if(i+1 < n)
	     {
		     sum += i+1;
	     }
     }
#endif
     clock_t stop = clock();


     //Calculate the elapsed time 
      double time_taken = ((double)(stop - start));
      printf("time taken %f \n",time_taken);
      printf("sum: %d\n", sum);
      return 0;
}

