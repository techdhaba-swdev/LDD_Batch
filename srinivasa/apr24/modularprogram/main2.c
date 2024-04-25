#include<stdio.h>
#include "main2.h"
int main(){
push(10);
push(20);
push(30);
push(40);
push(50);
printf("popped value: %d\n",pop());
printf("popped value:%d\n",pop());
return 0;
}
