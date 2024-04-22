#include <stdio.h>
int main()
{
int arr[] = {10,20,30,40,50};
int *ptr = arr;
printf("1st element : %d\n",*ptr);
printf("2nd element : %d\n",*(ptr+1));
printf("3nd element : %d\n",*(ptr+2));
printf("4th element : %d\n",*(ptr+3));
printf("5th element : %d\n",*(ptr+4));
return 0;
}
