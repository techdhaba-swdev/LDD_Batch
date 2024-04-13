#include<stdio.h>
int fibo(int n){
    if(n<=1){
        return n;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}
void print_fibo_series(int n){
    for(int i=0;i<n;i++)
    {
        printf("%d",fibo(i));
    }
    printf("\n");
    }
int main(){
    int num=10;
    printf("fibonaci series %d :",num);
    print_fibo_series(num);
    return 0;
}
