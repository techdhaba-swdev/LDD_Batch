#include<stdio.h>

int main() {
	int arr[5];

	int i, new;
	printf("enter 3 elements\n");
	for ( i=0;i<3;i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("enter the new number\n");
	scanf("%d",&new);

	for(i=2;i>=1;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[1]=new;

	printf("array after insertion\n");
	for(int i=0;i<4;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
		return 0;
}

