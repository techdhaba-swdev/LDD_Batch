#include <stdio.h>
#include<stdlib.h>
int main()
{
	int* ptr = (int*)malloc(sizeof(int));//dynamically allocates memory using malloc
	printf("%x\n",&ptr);
	free(ptr);//now we frees memory using free()
		  printf("%x\n",&ptr);

	*ptr =42;//after freeing the memorylocation it assigns value 42 to the memorylocation pointed to ptr accessing memory after its been freed can lead to undefined behaviour
	printf("%d\n",*ptr);
	return 0;
}

