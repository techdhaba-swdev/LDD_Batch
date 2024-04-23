#include<stdio.h>
#include<dlfcn.h>
int main(){
	void *lib_hello = dlopen("./example.so",RTLD_LAZY);
	if(!lib_hello){
		fprintf(stderr, "error:%s\n",dlerror());
		return 1;
	}
	int (*add)(int a,int b) = dlsym(lib_hello,"add");
	int (*sub)(int a,int b) = dlsym(lib_hello,"sub");
	int (*mul)(int a,int b) = dlsym(lib_hello,"mul");
	float(*div)(float a, float b) = dlsym(lib_hello,"div");


	int a=20,b=10;
	printf("addition :%d\n",add(a,b));
	printf("subtraction:%d\n",sub(a,b));
	printf("multiplication:%d\n",mul(a,b));
	printf("division:%f\n",div(a,b));

	dlclose(lib_hello);
	return 0;
}
