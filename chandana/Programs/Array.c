#include <stdio.h>

int main() {
	int arr[] = {10,23,1 ,54,67,89,19,4,6,1};
	int n=sizeof(arr) / sizeof(arr[0]);
	int min = arr[0];
	int max= arr[0];

	for (int i=1;i<n;i++) {
		if(arr[i] <min){
			min = arr[i];
                        }
		if(arr[i] > max ){
			max = arr[i];
		}
	}
	printf("Smallest element %d\n",min);
	printf("largest element :%d \n",max);

	return 0;
}
