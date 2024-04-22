//gcc -shared -fPIC -o libexample.so example.c
//gcc main.c -o dynamic_example -ldl


// main.c

#include <stdio.h>

#include <dlfcn.h>
 
int main() {

    // Load the shared library

    void *lib_handle = dlopen("./libexample.so", 
    );

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



