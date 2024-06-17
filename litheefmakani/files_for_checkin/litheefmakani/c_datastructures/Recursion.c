#include<stdio.h>
void print_num(int n){
    if(n<10){
        printf("%d \n",n);
        print_num(n+1);
    }
}
int main(){
    print_num(0);
    return 0;
}




































































