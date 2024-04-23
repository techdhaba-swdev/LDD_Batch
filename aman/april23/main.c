#include<stdio.h>
#include<dlfcn.h>
int main(){
void* handle= dlopen("./calculator.so", RTLD_NOW);
if (!handle){
	fprintf(stderr, "error: %s\n", dlerror());
	return 1;
}
int (*add)(int, int) = dlsym(handle, "add");
int (*sub)(int, int) = dlsym(handle, "sub");
int (*multiply)(int, int) = dlsym(handle, "multiply");
int (*divide)(int, int) = dlsym(handle, "divide");

if(!add || !sub || !multiply || !divide) {
	fprintf(stderr, "error: %s\n", dlerror());
	dlclose(handle);
	return 1;
}
int x= 10, y = 5;
printf("addition: %d\n", add(x, y));
printf("substraction: %d\n", sub(x, y));
printf("multiplication: %d\n", multiply(x, y));
printf("division: %d\n", divide(x, y));
dlclose(handle);
return 0;
}
