#include <stdio.h>
void array_reverse(int arr[], int size)
{
    int front =0;
    int last = size -1;
    int temp;
    while(front<last)
    {
      temp = arr[front];
      arr[front]=arr[last];
      arr[last] = temp;
      front++;
      last--; 
    }
}
int main()
{
    int arr[] = {10,11,12,13,14,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    array_reverse(arr,size);
    printf("revese array\n");
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}