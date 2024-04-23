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
	int(*mult)(int,int) = dlsym(lib_handle,"mult");
        if(!mult){
                fprintf(stderr,"Error :%s\n",dlerror());
                dlclose(lib_handle);
                return 1;
	}
	int(*div)(int,int) = dlsym(lib_handle,"div");
        if(!div){
                fprintf(stderr,"Error :%s\n",dlerror());
                dlclose(lib_handle);
                return 1;
	}

	int out_sum = add(20,15);
	int out_sub = sub(20,15);
        int out_mul = mult(20,15);
	int out_div = div(20,5);
	printf("sum :%d\n",out_sum);
	printf("subract :%d\n",out_sub);
	printf("mul :%d\n",out_mul);
	printf("div :%d\n",out_div);
	dlclose(lib_handle);

	return 0;
}

