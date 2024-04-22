#include<stdio.h>
#include <dlfcn.h>

int main(){
	void *lib_handle = dlopen("./fun_def.so",RTLD_LAZY);
	if(!lib_handle){
		fprintf(stderr ,"Error loading :%s\n",dlerror());
		return 1;
	}
	
	int(*add)(int,int) = dlsym(lib_handle,"add");
	if(!add){
		fprintf(stderr,"Error :%s\n",dlerror());
		dlclose(lib_handle);
		return 1;
	}
	int(*sub)(int,int) = dlsym(lib_handle,"sub");
	if(!sub){
		fprintf(stderr,"Error :%s\n",dlerror());
		dlclose(lib_handle);
		return 1;
	}

	int out_sum = add(20,15);
	int out_sub = sub(20,15);

	printf("sum :%d\n",out_sum);
	printf("subract :%d\n",out_sub);
	
	dlclose(lib_handle);

	return 0;
}

