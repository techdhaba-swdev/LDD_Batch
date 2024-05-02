#include<stdio.h>
#include<time.h>

int swap(int *x,int *y)
{
	int temp = *x;
	   *x = *y;
	   *y = temp;
}


int main()
{
	clock_t start = clock();
	 int x =5;
	 int y = 3;
	 printf("Before swap x = %d and y = %d\n",x,y);
	 swap(&x,&y);
	 printf("After swap x = %d and y = %d\n",x,y);
	 clock_t stop = clock();
	 double time = ((double)(stop - start));
	 printf("Time = %f\n",time);
	 return 0;
}
