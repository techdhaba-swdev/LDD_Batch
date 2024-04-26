#include <stdio.h>

#include <dlfcn.h>
 
int main() {

    // Load the shared library

    void *lib_handle = dlopen("./wm3.so", RTLD_LAZY);

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
 
    // Call the function

    hello_dynamic();
 
    // Close the library

    dlclose(lib_handle);
 
    return 0;

}
