#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for(int i =0;i<n; i++)
	{
		swapped = false;
		for(j = 0; j<n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = temp;
                                swapped = true;
			}


		}
	        if (swapped == false)
                      break;
	}
}

int main() 
{
	int arr[6] = {4,3,6,2,8,7};
	bubbleSort(arr, 6);
	for(int i =0; i<6; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
