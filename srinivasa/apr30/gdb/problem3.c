#include<stdio.h>
#include<time.h>

int main()
{
	clock_t start = clock();
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
	clock_t end = clock();
	float time = ((float)(end - start ));
	printf("run time : %f\n",time);
	return 0;
}
