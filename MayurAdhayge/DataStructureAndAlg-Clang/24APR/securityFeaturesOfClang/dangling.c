#include<stdio.h>
#include<stdlib.h>
void main(){
int b=85;

int* ptr = (int*) malloc(sizeof(int));
printf("%x",ptr);
free(ptr);
*ptr = 42; 
printf("%d",*ptr);
printf("%x",ptr);

}
