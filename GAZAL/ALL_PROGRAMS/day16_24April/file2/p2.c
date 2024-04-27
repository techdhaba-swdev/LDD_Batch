#include<stdio.h>
int main(){
	int* ptr=(int*)malloc(sizeof(int));
	printf("value of ptr is =%d\n",*ptr);
	free(ptr);//deallocate memory
		  *ptr = 42;//using adangling pointer can crash
			    printf("value of ptr is =%d\n",*ptr);
			    return 0;
}
	        
