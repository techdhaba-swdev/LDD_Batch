#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

//define the function signature for registration functions
tydef void(*RegisterFunc)(void);
//define a structure to hold function pointers
typedef struct{
	RegisterFunc register_func;
	void(*callback_func)(int);
}Module;
//Registerion function 
void register_module(){
	printf("Module registered succesfully!\n");
}
//call back function 
void callback_function(int value){
	printf("callback:Received value:n%d\n",value);
}
int main(){
	void *handle;
	Module module;i
	RegisterFunc register_func;
	//open the shared library
	handle=dlopen("./libmodule.so",RTLD_NOW | RTLD_GLOBAL);
	if(!handle){
		fprintf(stderr,"Error : %s\n",dlerror());
		//return 1;
	}
	//get the registration function
	register_func = (RegisterFunc)dlsym(handle,"register_module");
	if(!register_func){
		fprintf(stderr,"Error: %s\n",dlerror());
		dlclose(handle);
		return 1;
	}
	//invoke the registration function
	register_func();
	//store callback function pointer 
	module.callback_func = callback_function;
	//call the callback function through the pointer
	module.callback_func(42);
	//unload the shared library
	if(dlclose(handle)!=0){
		fprintf(stderr,"Error:%s\n",dlerror());
		return 1;
	}
	return 0;
}

