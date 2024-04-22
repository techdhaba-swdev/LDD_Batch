#include<stdio.h>
#include<dlfcn.h>

int main(){
	void *lib_handle = dlopen("./libcal.so",RTLD_LAZY);
	if(!lib_handle){
		fprintf(stderr,"error %s\n",dlerror());
		return 1;
	}
	int(*add)(int,int)= dlsym(lib_handle,"add");
	int(*subtract)(int,int)= dlsym(lib_handle,"subtract");
	int(*multiply)(int,int)= dlsym(lib_handle,"multiply");
	int(*divide)(int,int)= dlsym(lib_handle,"divide");
	if(!add||!subtract||!multiply||!divide){
		fprintf(stderr,"error:%s\n",dlerror());
		dlclose(lib_handle);
		return 1;
	}
	int a=10, b=20;

	printf("%d\n",add(a,b));
	printf("%d\n",subtract(a,b));
	printf("%d\n",multiply(a,b));
        printf("%d\n",divide(a,b));
	dlclose(lib_handle);
	return 0;
}


