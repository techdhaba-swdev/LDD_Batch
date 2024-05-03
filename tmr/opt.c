#include<stdio.h>
#include<time.h>
int main()
{
	clock_t start = clock();
	int sum = 1;
	int n = 10000;
	//original loop(less efficient)
	/*for (int i =0; i<n; i++)
	  {
	    sum =i+1;
	   }*/
	//unrolled loop (improves perfomance for smll loop iterations)
	for (int i =1; i < n; i+=2)
	{
		sum +=i;

		clock_t end =clock();
		double time_taken = ((double)(end - start));
                if(i+1 <n)
		{
			sum += i+1;
		}
	}
	printf("sum: %d",sum);
	printf("time taken: %f seconds\n",time_taken);

	return 0;
}
	
