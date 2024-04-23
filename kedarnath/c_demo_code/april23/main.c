#include <stdio.h>
#include <dlfcn.h>


int main() {

    // Open the shared object file
    void* libHandle = dlopen("./example.so", RTLD_LAZY);
    if (!libHandle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    // Load the function symbol
    
    int (*add)(int,int)=dlsym(libHandle,"add");
    int (*sub)(int,int)=dlsym(libHandle,"sub");
    int (*mul)(int,int)=dlsym(libHandle,"mul");
    float (*div)(int,int)=dlsym(libHandle,"div");
    
    if (!add) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }
    
    if (!sub) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }
    
    if (!mul) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }
    
    if (!div) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }
    
    printf("sum is %d\n",add(10,20));
    printf("substraction is %d\n",sub(30,10));
    printf("multiplication is %d\n",mul(10,20));
    printf("division is %f\n",div(8,3));
    
    // Close the shared object file
    dlclose(libHandle);

    return 0;
}




