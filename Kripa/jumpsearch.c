#include<stdio.h>
#include<math.h>

#define min(x,y) ((x)< (y)? (x):(y))
int jumpsearch (int a[], int n, int K)
{
    int t =0;
    int b = (int)sqrt(n);
    while(a [min(b,n)-1] <K){
        t=b;
        b=b+(int)sqrt(n);
        if(t>=n) return -1;
    }
    while (a[t]<K){
        t=t+1;
        if(t==min(b,n))
        return -1;
        if(a[t]==K){
            return t;
        }
    }
    int main(){
        int a[7] ={3,7,9,12,15,14,16};
        int K=14;
        printf("Element found at the position %d/n", jumpsearch(a,7,K));
        return 0;
    }
}