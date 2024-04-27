#include <stdio.h>
#include <math.h>
#include"jump.h"
#define min(x,y) ( (x)<(y) ? (x):(y) )

// Jump search function
int jumpSearch(int a[], int k, int n) {
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

