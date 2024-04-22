#include <stdio.h>
#include <dlfcn.h>

int main() {
	void *lib_handle = dlopen("./libexample.so",RTLD_LAZY);

	if(!lib_handle) {
		fprintf(stderr,"Error: %s\n",dlerror());
		return 1;
	}

	//get a pointer to the function 
	void(*hello_dynamic)()=dlsym(lib_handle,"hello_dynamic");
	if(!hello_dynamic){
		fprintf(stderr,"Error:%s\n",dlerror());
		dlclose(lib_handle);
		return 1;
	}

	//call the function
	hello_dynamic();

	//close the library
	dlclose(lib_handle);

	return 0;
}
	
