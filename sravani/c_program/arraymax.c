#include<stdio.h>
int main(){
	int arr[]={1,2,3,4,5,6,};
	int n =sizeof(arr)/sizeof(arr[0]);
	int largest = arr[0];
	int small = arr[0];
	for(int i =1;i<n;i++)
		if(arr[i]<small)
		{
			small =arr[i];
		}
	if(arr[i]>largest)
	{
          largest =arr[i];
	}

printf("small:%d\n" ,small);
printf("largest:%d\n",largest);
return 0;
}
             
