#include<stdio.h>
#include<dlfcn.h>
int main(){
	void *lib_handle=dlopen("./libswap.so",RTLD_LAZY);
	if(!lib_handle){
		fprintf(stderr,"Error:%s\n",dlerror());
		return 1;
	}
	void (*swap)(int *,int*)=dlsym(lib_handle,"swap");
	int a=5;
	int b=10;
	printf("before swap:%d %d\n",a,b);
	swap(&a,&b);
	printf("after swap:%d %d\n",a,b);
	dlclose(lib_handle);
	return 0;
}

