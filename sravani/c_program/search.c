#include<stdio.h>
int linearSearch(int arr[],int n,int m){
	for(int i=0;i<n;i++)
	{
		if(arr[i] == m){
			return i;
		}
	}
	return -1;
}
int main(){
	int arr[]={1,2,3,4,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	int m = 5;
	int result = linearSearch(arr,n,m);
	if(result=-1){
		printf("%d is not found:\n",m);
	}else{
		printf("%d is found :\n",m,result);
}
return 0;
}

