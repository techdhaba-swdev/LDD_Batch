#include <stdio.h>

int main(){
	int arr[]={12,56,34,2,6,1,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key =7;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			printf("key found",i);
			flag=1;
			break;
		}
	}
		if(flag==0)
		{
			printf("key not found ");
		}
}

