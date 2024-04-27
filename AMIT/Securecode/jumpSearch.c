#include<stdio.h>
#include<math.h>
//#include"jump.h"

#define min(x,y) ( (x)<(y) ? (x):(y) )

int jumpSearch(int a[],int n,int k)
{
        int t=0;
        int b=(int)sqrt(n);
        while(a[min(b,n)-1]<k)
        {
                t=b;
                b=b+(int)sqrt(n);
                if(t>=n)
                        return -1;
        }
        while(a[t]<k)
        {
                t=t+1;
                if(t==min(b,n))
                        return -1;
                if(a[t]==k)
                        return t;
        }
}


    int main()
{
        int a[7]={3,7,9,12,14,15,16};
        int k=14;
        printf("Element found at position %d \n",jumpSearch(a,7,k));
        return 0;
}


