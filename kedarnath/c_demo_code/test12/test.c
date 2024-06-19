#include<linux/module.h> 
#include<linux/init.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");  

static int __init hello_init(void){

	printk(KERN_INFO "hello from init  module\n");
	return 0;

}

static void __exit hello_exit(void){
	printk(KERN_INFO "hello from exit module\n");

}

module_init(hello_init);
module_exit(hello_exit);


