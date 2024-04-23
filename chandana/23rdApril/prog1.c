#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

//Define the function signature for registration functions
typedef void (*RegisterFunc)
	(void);
//Define the structure to hold functions pointers
	typedef struct {
		RegisterFunc register_func;
		void(*callback_func)(int);
	}Module;
//Registration function
void register_module() {
	printf("Module registered successfully\n");
}
//callback function
void callback_function(int value) {
	printf("Callback:Received value:%d\n",value);
}

int main() {
	void *handle;
	Module module;
	RegisterFunc register_func;
//open the shared library
	handle=dlopen("./libmodule.so",RTLD_NOW | RTLD_GLOBAL);
	if(!handle) {
		fprintf(stderr,"Error : %s\n",dlerror());
		return 1;
	}
	//Get the registrtion function
	register_func = (RegisterFunc)dlsym(handle,"register_module");
	if(!register_func){
		fprintf(stderr,"Error : %s\n",dlerror());
		dlclose(handle);
		return 1;
	}
	//invoke the registration function
	register_func();
//store callback function pointer
	module.callback_func=callback_function;
//call the callback function through the pointer
	module.callback_func(42);
//unload the shared library 
	if(dlclose(handle)!=0){
		fprintf(stderr,"Error:%s\n",dlerror());
		return 1;
	}
	return 0;
}
