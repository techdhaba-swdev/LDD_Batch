#include<stdio.h>
#include<dlfcn.h>
int main()
{
	void *lib_handle=dlopen("./libexample1.so",RTLD_LAZY);
	if(!lib_handle)
	{
		fprintf(stderr, "Error:%s\n", dlerror());
		return 1;
	}
	int(*add)(int,int)=dlsym(lib_handle,"add");
	int(*sub)(int,int)=dlsym(lib_handle,"sub");
	int(*mul)(int,int)=dlsym(lib_handle,"mul");
	int(*div)(int,int)=dlsym(lib_handle,"div");
	int n1=6, n2=12;
	printf("add:%d.2f\n",add(n1,n2));
	printf("sub:%d.2f\n",sub(n1,n2));
	printf("mul:%d.2f\n",mul(n1,n2));
	printf("div:%d.2f\n",div(n1,n2));
	return 0;
}