#include <stdio.h>
int linearsearch(int arr[],int find)
{
    for (int i = 0; i< 5; i++)
    {  
        if (arr[i] == find)
        {  
            return i;  
        }  
    }  
        return -1;  
}  
