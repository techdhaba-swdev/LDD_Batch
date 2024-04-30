#include <stdio.h>
#include <time.h>
int main() {
	int sum =0;
	int n=1000;

	for(int i=0;i<n;i+=2){
		sum +=i;
		if(i+1<n){
			sum+=i+1;
		}
	}
	printf("sum is %d\n",sum);
}
