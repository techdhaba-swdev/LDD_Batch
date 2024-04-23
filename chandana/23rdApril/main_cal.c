#include <stdio.h>
#include <dlfcn.h>

int main() {
	//load the shared library
	void *lib_handle = dlopen("./libcal.so",RTLD_GLOBAL);
	if(!lib_handle){
		fprintf(stderr,"Error: %s\n",dlerror());
		return 1;
	}

	int (*add)(int,int)=dlsym(lib_handle,"add");
	int (*sub)(int,int)=dlsym(lib_handle,"sub");
	int (*mul)(int,int)=dlsym(lib_handle,"mul");
	int (*div)(int,int)=dlsym(lib_handle,"div");

	if(!add ||!sub || !mul || !div){
		fprintf(stderr,"Error:%s\n",dlerror());
		dlclose(lib_handle);
		return 1;
	}
	//call  the functions
	printf("Addition :%d\n",add(10,5));
	printf("Subtraction :%d\n",sub(10,5));
	printf("Multiplication : %d \n",mul(10,5));
	printf("Division : %d\n",div(10,5));

	dlclose(lib_handle);

	return 0;
}
