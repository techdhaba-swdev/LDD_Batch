#define concat(a,b) a##b
#include <stdio.h>
#include <string.h>
int main(){
    char name1[7]="hello";
    char name2[7]="world";
    char result[20];
    strcpy(result,concat(name1,name2));
    printf("%s\n",result);
    return 0;
}