#include<stdio.h> 
#define begin(m,a,i,n) m##a##i##n 
#define start begin(m,a,i,n)
 
void start() { 
printf("Geeksforgeeks"); 
}
