//Buffer overflow
#include <stdio.h>

int main(){

char buffer[10];
scanf("%s",buffer);
printf("entered word is %s\n",buffer);

}
