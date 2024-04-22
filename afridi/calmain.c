#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *lib_handle = dlopen("./libexample1.so", RTLD_LAZY);
    if (!lib_handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    int (*add_dynamic)(int, int) = dlsym(lib_handle, "add_dynamic");
    int (*sub_dynamic)(int, int) = dlsym(lib_handle, "sub_dynamic");
    int (*mul_dynamic)(int, int) = dlsym(lib_handle, "mul_dynamic");
    int (*div_dynamic)(int, int) = dlsym(lib_handle, "div_dynamic");

    if (!add_dynamic || !sub_dynamic || !mul_dynamic || !div_dynamic) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(lib_handle);
        return 1;
    }

    add_dynamic(2, 3);
    sub_dynamic(10, 30);
    mul_dynamic(10, 20);
    div_dynamic(10, 20);

    dlclose(lib_handle);
    return 0;
}
