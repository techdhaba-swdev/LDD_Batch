#include<stdio.h>
#include<dlfcn.h>

int main(){

void *lib_handle=dlopen("./libcalculator.so", RTLD_LAZY);
if(!lib_handle)
{

fprintf(stderr, "Erroг:%s\n",dlerror());

return 1;

}
int (*add) (int,int)=dlsym(lib_handle, "add");
int (*sub)(int,int)=dlsym(lib_handle, "sub");
int (*mul)(float,float)=dlsym(lib_handle, "mul");
int (*div)(float,float)=dlsym(lib_handle, "div");
int  n1=10, n2=5;
printf("add:%.2d\n",add(n1,n2));
printf("sub:%.2d\n",sub(n1,n2)); 
printf("mul:%.2f\n",mul(n1,n2));
printf("div:%.2f\n", div(n1,n2));

dlclose(lib_handle);
return 0;
}



