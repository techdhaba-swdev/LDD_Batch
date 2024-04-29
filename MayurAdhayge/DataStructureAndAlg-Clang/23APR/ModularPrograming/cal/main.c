#include "main.h"

void main(){
/*
pthread_t add1,add2,add3;
pthead_t sub1,sub2,sub3;
pthread_t div1,div2,div3;

pthread_create(&add,NULL,int add,2,1,2)
pthread_join();*/

printf("addition of number-\n");
printf("add two - 1+2=%d\n",add(2,1,2));
printf("add three - 1+2+3=%d\n",add(3,1,2,3));
printf("add four - 1+2+3+4=%d\n",add(4,1,2,3,4));

printf("substraction of number-\n");
printf("sub two - 10-5=%d\n",sub(2,10,5));
printf("sub three - 100-25-3=%d\n",sub(3,100,25,3));
printf("sub four - 100-50-3-4=%d\n",sub(4,100,50,3,4));


printf("division of number-\n");
printf("div two - 10/2=%.2f\n",div(2,10,2));
printf("add three - 10/2/5=%.2f\n",div(3,10,2,5));
printf("add four - 100/2/5/2=%.2f\n",div(4,100,2,5,2));


}

