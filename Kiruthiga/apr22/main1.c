#include<stdio.h>
#include<dlfcn.h>
int main()
{
	void *lib_handle = dlopen("./libcal.so",RTLD_LAZY);
	if(!lib_handle){
	fprintf(stderr,"error %s\n",dlerror());
	return 1;
}
int(*add)(int,int) = dlsym(lib_handle,"add");
int(*sub)(int,int) = dlsym(lib_handle,"sub");
int(*mul)(int,int) = dlsym(lib_handle,"mul");
int(*divide)(int,int) = dlsym(lib_handle,"divide");
if(!add||!sub||!mul||!divide){
fprintf(stderr,"error :%s\n",dlerror());
dlclose(lib_handle);
return 1;
}
int a=30, b = 10;
printf("%d\n",add(a,b));
printf("%d\n",sub(a,b));
printf("%d\n",mul(a,b));
printf("%d\n",divide(a,b));
dlclose(lib_handle);
return 0;
}
