#include<stdio.h>
#include<time.h>

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main () {
        clock_t start = clock(); //start the close
	int x=5;
	int y=10;
	clock_t end = clock(); //stop the clock
	double time_taken = ((double)(end - start)); //cal the elapsed time'
	printf("before swap x=%d y=%d\n",x,y);
	swap(&x,&y);
	printf("after swap x=%d y=%d\n",x,y);
	printf("Time taken: %f seconds \n",time_taken);
return 0;
}

