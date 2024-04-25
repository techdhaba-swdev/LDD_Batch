#include <stdio.h>
#include <stdlib.h>

int main() {
int* ptr = (int*) malloc(sizeof(int));//Allocate memeory
printf("after allocating memory %d\n",*ptr);
free(ptr);//Dealloacte memeory
printf("after free %d\n",*ptr);
*ptr=42;//using a dangling pointer can crash
printf("value:%d\n",*ptr);
printf("after free the ptr %d\n",ptr);
return 0;
}
