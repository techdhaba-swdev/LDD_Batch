#include<stdio.h>
#include<dlfcn.h>
#include<unistd.h>

//hello_dynamic
int main(){
	//load the shared library
	void *lib_handle=dlopen("./dynamically.so",RTLD_LAZY);
	if(!lib_handle){
		fprintf(stderr,"Error:%s\n",dlerror());
		return 1;
	}
	//get a pointer to thefunction 
	void(*hello_dynamic)()=dlsym(lib_handle,"hello_dynamic");
		if(!hello_dynamic){
			fprintf(stderr,"Error:%s\n",dlerror());
			dlclose(lib_handle);
			return 1;
		}
		//call the function hello_dynamic();
		hello_dynamic();

		//close the library dlclose(lib_handle);
		dlclose(lib_handle);
		return 0;
}
