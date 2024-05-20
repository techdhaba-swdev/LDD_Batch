#include "merge.h"

void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; // Temporary arrays to hold subarrays  
      
    // Copy data to temp arrays  
    for (int i = 0; i < n1; i++)    
        LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
        RightArray[j] = a[mid + 1 + j];    
      
    i = 0; // Initial index of first sub-array  
    j = 0; // Initial index of second sub-array  
    k = beg; // Initial index of merged sub-array  
      
    // Merge the two subarrays into a single sorted subarray  
    while (i < n1 && j < n2)    
    {    
        if (LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
      
    // Copy the remaining elements of LeftArray, if any  
    while (i < n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    // Copy the remaining elements of RightArray, if any  
    while (j < n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}
