#include<stdio.h>
int main(){

    int a=100,b=200;
    printf("before swapping a is %d and b is %d\n",a,b);
    a=a*b;
    b=a/b;
    a=a/b;
    printf("before swapping a is %d and b is %d\n",a,b);


}