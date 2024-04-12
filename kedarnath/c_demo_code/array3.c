#include<stdio.h>
int main(){

	int arr[5];
	for(int i=0;i<3;i++){
		scanf("%d",&arr[i]);
	}
	int add=20;
	for(int i=3;i>=2;i--){
		int temp=arr[i];
		arr[i]=arr[i-1];


	
	
	}
	arr[1]=add;
	for(int i=0;i<4;i++){
		printf("%d is %d\n",i,arr[i]);
	}
}

