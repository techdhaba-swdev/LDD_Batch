#include<stdio.h>

#define SWAP(a,b)do{ \
    typeof(a) temp = (a);\
    (a) = (b);\
    (b) = temp;\
} while (0)
int main(){
    int x=5, y=10;
    printf("Before swapping: x= %d\n,y= %d\n",x,y);
    SWAP(x,y);
    printf("After swapping: x= %d,y= %d\n",x,y);
    return 0;


}