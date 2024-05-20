// C program for insertion sort
#include <math.h>
#include <stdio.h>
 
/* Function to sort an array 
using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) //from second element
	{
		key = arr[i];//selecting the element to be inserted
		j = i - 1;//initialize j to index befor key
 
		/* Move elements of arr[0..i-1], 
		that are greater than key, 
		to one position ahead of 
		their current position */
		while (j >= 0 && arr[j] > key) if//if j is within bound and arr is greater than key
		{
			arr[j + 1] = arr[j];//shift to right
			j = j - 1;//move to previous
		}
		arr[j + 1] = key;//insert the key element in crt position
	}
}
 
// A utility function to print 
// an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
 
// Driver code
int main()
{
	int arr[] = {12, 11, 13, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
 
	insertionSort(arr, n);
	printArray(arr, n);
 
	return 0;
}















