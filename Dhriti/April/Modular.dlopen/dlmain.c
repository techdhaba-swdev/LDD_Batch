#include<stdio.h>
#include<dlfcn.h>


int main(){

	void *lib_handle = dlopen("./libexample.so", RTLD_lAZY);

	if(!handle) {
		fprintf(stderr, 
