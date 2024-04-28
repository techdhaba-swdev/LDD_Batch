#include <stdio.h>

#include <dlfcn.h>
 
int main() {

    // Load the shared library

    void *lib_handle = dlopen("./libcalculator.so", RTLD_LAZY);

    if (!lib_handle) {

        fprintf(stderr, "Error: %s\n", dlerror());

        return 1;

    }

    void *handle = dlopen("./mylibaddsub.so",RTLD_LAZY);
    if(!handle)
    {
	   fprintf(stderr,"Error: %s\n",dlerror());
	  return 1;
    } 
    // Get a pointer to the function

    int (*calcul_dynamic)(int ,int) = dlsym(lib_handle, "calcul_dynamic");

    if (!calcul_dynamic) {

        fprintf(stderr, "Error: %s\n", dlerror());

        dlclose(lib_handle);

        return 1;

    }
    int (*add)(int,int) = dlsym(handle,"add");
    if(!add)
    {
	    fprintf(stderr,"Error:%s\n",dlerror());
    }
    int (*sub)(int,int) = dlsym(handle,"sub");
    if(!sub)
    {
	    fprintf(stderr,"Error:%s\n",dlerror());
    }
 
    // Call the function

    calcul_dynamic(add(22,5),sub(22,5));
 
    // Close the library

    dlclose(lib_handle);
 
    return 0;

}

