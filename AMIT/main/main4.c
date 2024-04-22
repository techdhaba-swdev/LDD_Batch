#include<stdio.h>
#include<dlfcn.h>

int main()
{
	void *lib_handle= dlopen("./libex4.so",RTLD_LAZY);  //Load shared libraries
	
	if (!lib_handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    // Get a pointer to the function
    void (*hello_dynamic)() = dlsym(lib_handle, "hello_dynamic");
    if (!hello_dynamic) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(lib_handle);
        return 1;
    }

    hello_dynamic();
    dlclose(lib_handle);
    return 0;
}
