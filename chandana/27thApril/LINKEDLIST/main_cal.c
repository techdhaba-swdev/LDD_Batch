//Standard Input/Output library.
#include <stdio.h>
#include <dlfcn.h>

int main() {
	//load the shared library
	void *lib_handle = dlopen("./libcal.so",RTLD_GLOBAL);
	if(!lib_handle){
		//checks if the handle to the dl is null
		fprintf(stderr,"Error: %s\n",dlerror());
		//prints the error msg to the standard eror stream 
		return 1;
		//return 1 indicates an error occurred.
	}

	int (*add)(int,int)=dlsym(lib_handle,"add");
	//declares a function pointer add and uses dlsysm to dl the fun add from the loaded library
	int (*sub)(int,int)=dlsym(lib_handle,"sub");
	//declares a function pointer sub and uses dlsysm to dl the fun sub from the loaded library
	int (*mul)(int,int)=dlsym(lib_handle,"mul");
	//declares a function pointer mul and uses dlsysm to dl the fun mul  from the loaded library
	int (*div)(int,int)=dlsym(lib_handle,"div");
	//declares a function pointer div and uses dlsysm to dl the fun div from the loaded library

	if(!add ||!sub || !mul || !div){
		//checks if any function pointers are  null.
		fprintf(stderr,"Error:%s\n",dlerror());
		//prints the error msg
		dlclose(lib_handle);
		//claoes the library 
		return 1;
		//indicate an error occured
	}
	//call  the functions
	//function call with meanining ful variable names
	printf("Addition :%d\n",add(10,5));
	printf("Subtraction :%d\n",sub(10,5));
	printf("Multiplication : %d \n",mul(10,5));
	printf("Division : %d\n",div(10,5));

	dlclose(lib_handle);
//indiacte successful program termination.
	return 0;
}
