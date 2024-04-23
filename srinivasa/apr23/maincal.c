#include<stdio.h>
#include<dlfcn.h>
int main()
{
	void *lib_handle=dlopen("./libcalculator.so", RTLD_LAZY);
	if(!lib_handle){
		fprintf(stderr, "Erroг:%s\n",dlerror());
		return 1;
	}
       	double (*add)(double,double)=dlsym(lib_handle, "add");
	double (*sub)(double,double)=dlsym(lib_handle, "sub");
	double (*mul)(double,double)=dlsym(lib_handle, "mul"); 
	double (*div)(double,double)=dlsym(lib_handle, "div");
	
	double n1=10, n2=5;
	printf("add:%.2f\n",add(n1,n2));
       	printf("sub:%.2f\n",sub(n1,n2)); 
	printf("mul:%.2f\n",mul(n1,n2));
       	printf("div:%.2f\n", div(n1,n2));
	dlclose(lib_handle);
	return 0;
}
