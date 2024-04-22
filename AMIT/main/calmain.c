#include <stdio.h>
#include <dlfcn.h>
 
int main() {
    // Load the shared library
    void *lib_handle = dlopen("./calculatorlib.so", RTLD_LAZY);
    if (!lib_handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }
 
    // Get a pointer to the function
    void (*calculator)() = dlsym(lib_handle, "calculator");
    if (!calculator) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(lib_handle);
        return 1;
    }
 
    // Call the function
     calculator();
 
    // Close the library
    dlclose(lib_handle);
 
    return 0;
}
