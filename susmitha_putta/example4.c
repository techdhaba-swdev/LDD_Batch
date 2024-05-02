#include<stdio.h>
#include<time.h>
int main(){
	int sum =0;
	int n =1000;

	for(int i = 0; i < n; i += 2)
	{
	sum +=i;
	clock_t start =clock();
	if(i + 1 < n)
	{
		sum += i+1;
	}
}
clock_t stop = clock();
printf("Sum: %d\n",sum);
return 0;
}
