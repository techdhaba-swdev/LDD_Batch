#include <stdio.h>
#include <dlfcn.h>

int main(){
	void *lib_handle= dlopen("./libexample.so",RTLD_LAZY);
	if(!lib_handle){
		fprintf(stderr, "error:%s\n",dlerror());
		return 1;
	}
	void (*hello_dynamic)()=dlsym(lib_handle,"hello_dynamic");
	if(!hello_dynamic){
		fprintf(stderr,"error: %s\n",dlerror());
		dlclose(lib_handle);
		return 1;
	}
	hello_dynamic();
	dlclose(lib_handle);
	return 0;
}

