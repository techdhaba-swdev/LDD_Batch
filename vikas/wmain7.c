#include <stdio.h>

#include <dlfcn.h>
 
int main() {


    void *lib_handle = dlopen("./wm6.so", RTLD_LAZY);

    if (!lib_handle) {

        fprintf(stderr, "Error: %s\n", dlerror());

        return 1;

    }
 

    void (*add)() = dlsym(lib_handle, "add");

    if (!add) {

        fprintf(stderr, "Error: %s\n", dlerror());

        dlclose(lib_handle);

        return 1;

    }

    void (*sub)() = dlsym(lib_handle, "sub");

    if (!sub) {

        fprintf(stderr, "Error: %s\n", dlerror());

        dlclose(lib_handle);

        return 1;

    }

    void (*mul)() = dlsym(lib_handle, "mul");

    if (!mul) {

        fprintf(stderr, "Error: %s\n", dlerror());

        dlclose(lib_handle);

        return 1;

    }

    void (*div)() = dlsym(lib_handle, "div");

    if (!div) {

        fprintf(stderr, "Error: %s\n", dlerror());

        dlclose(lib_handle);

        return 1;

    }


 
    // Call the function

    add();
    sub();
    mul();
    div();
 
    // Close the library

    dlclose(lib_handle);
 
    return 0;

}

