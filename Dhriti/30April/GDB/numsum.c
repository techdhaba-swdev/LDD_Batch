#include<stdio.h>

int main()
{
	int sum=0;
	int n=1000;
        
	//original loop less efficient
	/*for(int i=0;i<n;i++) {
		sum += i;
	}*/

	//unrolled code
	for (int i=0;i<n;i+=2){
		sum += i;
		if(i+1<n){
			sum += i+1;
		}
	}
	
	printf("Sum: %d\n",sum);
	return 0;
}
